#include "NetQoSRequirementsIterator.h"

namespace CQML
  {

  NetQoSRequirementsIterator::NetQoSRequirementsIterator 
    (NetQoSVisitor const & nqv,
     NetQoSRequirements::iterator const &iter)
    : nqv_ (&nqv), 
      current_(iter)
    { }

  NetQoSRequirementsIterator & NetQoSRequirementsIterator::operator ++ ()
    {
      NetQoSRequirements::iterator iter = this->current_;
      for (;iter != nqv_->qos_conn_mmap_.end() && 
            iter->first == current_->first;
            ++iter);

      this->current_ = iter;
      return *this;
    }

  SharedNetQoS NetQoSRequirementsIterator::operator *() const
    {
      SharedNetQoS snq;
      NetQoSRequirements::iterator iter = this->current_;
      for (; iter != nqv_->qos_conn_mmap_.end() && 
             iter->first == current_->first;
             ++iter)
        {
          snq.netqos = iter->first;
          snq.conn_set.insert (iter->second);
        }
      return snq;
    }

  bool NetQoSRequirementsIterator::operator == 
    (NetQoSRequirementsIterator const &iter) const
    {
      return (this->nqv_ == iter.nqv_ && 
              this->current_ == iter.current_);
    }

  bool NetQoSRequirementsIterator::operator != 
    (NetQoSRequirementsIterator const &iter) const
    {
      return !(*this == iter);
    }

  } // namespace CQML
