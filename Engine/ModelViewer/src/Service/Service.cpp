#include "Service\Service.h"

namespace tools
{
	namespace service
	{
		Service::Service()
		{
			m_name = "empty service";
		}

		void Service::SetName(std::string name)
		{
			m_name = name;
		}
	}
}
