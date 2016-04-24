#include "Puppet.h"
#include "IPuppeteer.h"

USING_NS_CC;

bool CPuppet::init(IMapPhysics &mapPhysics)
{
    m_mapPhysics = &mapPhysics;
    return Node::init();
}

void CPuppet::onEnter()
{
    Node::onEnter();
    scheduleUpdate();
    if (m_puppeteer)
    {
        m_puppeteer->OnEnter();
    }
}

void CPuppet::onExit()
{
    unscheduleUpdate();
    if (m_puppeteer)
    {
        m_puppeteer->OnExit();
    }
    Node::onExit();
}

void CPuppet::update(float delta)
{
    if (m_puppeteer && m_mapPhysics)
    {
        m_puppeteer->Update(delta);
        const Vec2 oldPosition = getPosition();
        setPosition(oldPosition + delta * m_puppeteer->GetVelocity());
        if (!m_mapPhysics->CanStandOn(convertToWorldSpace(Vec2::ZERO)))
        {
            setPosition(oldPosition);
        }
    }
}

void CPuppet::SetPuppeteer(IPuppeteer *puppeteer)
{
    if (m_puppeteer && isRunning())
    {
        m_puppeteer->OnExit();
    }
    m_puppeteer = puppeteer;
    if (m_puppeteer && isRunning())
    {
        m_puppeteer->OnEnter();
    }
}
