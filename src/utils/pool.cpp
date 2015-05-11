#include "pool.h"
//----------------------------------------------------------------------------------------------
#include "api.h"
//----------------------------------------------------------------------------------------------
static EteraThreadPool* g_thread_pool = NULL;
//----------------------------------------------------------------------------------------------

void EteraThreadPool::init()
{
    g_thread_pool = new EteraThreadPool();
}
//----------------------------------------------------------------------------------------------

void EteraThreadPool::cleanup()
{
    delete g_thread_pool;
}
//----------------------------------------------------------------------------------------------

QThreadPool* EteraThreadPool::globalInstance()
{
    return g_thread_pool->m_pool;
}
//----------------------------------------------------------------------------------------------

EteraThreadPool::EteraThreadPool()
{
    EteraAPI::init();

    m_pool = new QThreadPool();
}
//----------------------------------------------------------------------------------------------

EteraThreadPool::~EteraThreadPool()
{
    EteraAPI::cleanup();

    m_pool->waitForDone();

    delete m_pool;
}
//----------------------------------------------------------------------------------------------
