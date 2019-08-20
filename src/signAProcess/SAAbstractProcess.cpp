#include "SAAbstractProcess.h"
#include <atomic>
class SAAbstractProcessPrivate
{
    SA_IMPL_PUBLIC(SAAbstractProcess)
public:
    SAAbstractProcessPrivate(SAAbstractProcess* p):q_ptr(p)
        ,m_isstop(true)
    {

    }
    ~SAAbstractProcessPrivate(){

    }

public:
    std::atomic_bool m_isstop;
};


SAAbstractProcess::SAAbstractProcess(QObject* par):QObject(par)
  ,d_ptr(new SAAbstractProcessPrivate(this))
{

}

SAAbstractProcess::~SAAbstractProcess()
{

}


/**
 * @brief 获取标识
 * 标识可以用于区分工作任务
 * @return
 */
uint SAAbstractProcess::getID() const
{
    return (uint)this;
}

void SAAbstractProcess::setStop(bool stop)
{
    d_ptr->m_isstop = stop;
}

bool SAAbstractProcess::isStop() const
{
    return d_ptr->m_isstop;
}