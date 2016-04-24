#include "CustomMap.h"

USING_NS_CC;

namespace
{
const char C_LAYER_NAME[] = "tiles";
const char C_OBSTACLES_LAYER_NAME[] = "obstacles";
const char C_PASSABILITY_PROP[] = "pass";

class CLayerBoolean
{
public:
    CLayerBoolean(TMXTiledMap & map, TMXLayer & layer, const std::string &name)
        : m_map(map)
        , m_layer(layer)
        , m_name(name)
    {
    }

    bool GetProperty(unsigned x, unsigned y)
    {
        uint32_t groupId = m_layer.getTileGIDAt(Vec2(x, y));

        auto cachedValueIt = m_cache.find(groupId);
        if (cachedValueIt != m_cache.end())
        {
            return cachedValueIt->second;
        }
        bool canPass = HasGroupBoolProperty(groupId);
        m_cache[groupId] = canPass;
        return canPass;
    }

private:
    bool HasGroupBoolProperty(uint32_t groupId)
    {
        ValueMap groupProps = m_map.getPropertiesForGID(int(groupId)).asValueMap();
        return groupProps[m_name].asBool();
    }

    TMXTiledMap & m_map;
    TMXLayer & m_layer;
    const std::string m_name;
    std::unordered_map<uint32_t, bool> m_cache;
};

}

bool CCustomMap::CanStandOn(const Vec2 &worldPosition) const
{
    Vec2 localPosition = TMXTiledMap::convertToNodeSpace(worldPosition);
    return std::none_of(m_obstacles.begin(), m_obstacles.end(), [=](const Rect &rect) {
        return rect.containsPoint(localPosition);
    });
}

bool CCustomMap::init(const std::string &tmxFile)
{
    return initWithTMXFile(tmxFile) && InitPassabilityMap() && LoadObstacles();
}

bool CCustomMap::InitPassabilityMap()
{
    TMXLayer *layer = TMXTiledMap::getLayer(C_LAYER_NAME);
    CLayerBoolean property(*this, *layer, C_PASSABILITY_PROP);
    const Size size = layer->getLayerSize();
    const unsigned width = static_cast<unsigned>(size.width);
    const unsigned height = static_cast<unsigned>(size.height);

    m_passability.resize(width * height);
    for (unsigned x = 0; x < width; ++x)
    {
        for (unsigned y = 0; y < height; ++y)
        {
            unsigned index = x + y * width;
            m_passability[index] = property.GetProperty(x, y);
        }
    }
    return true;
}

bool CCustomMap::LoadObstacles()
{
    TMXObjectGroup *group = TMXTiledMap::getObjectGroup(C_OBSTACLES_LAYER_NAME);
    try
    {
        std::vector<cocos2d::Rect> obstacles;
        cocos2d::Rect rect;
        for (Value object : group->getObjects())
        {
            ValueMap objectProps = object.asValueMap();
            rect.origin.x = objectProps.at("x").asFloat();
            rect.origin.y = objectProps.at("y").asFloat();
            rect.size.width = objectProps.at("width").asFloat();
            rect.size.height = objectProps.at("height").asFloat();
            obstacles.emplace_back(rect);
        }
        std::swap(obstacles, m_obstacles);
    }
    catch (const std::exception &)
    {
        return false;
    }
    return true;
}
