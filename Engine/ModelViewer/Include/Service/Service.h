#pragma once
#include <string>

namespace tools 
{
	namespace service
	{
		class Service {
		public:
			virtual ~Service() = default;

			virtual void Initialize() = 0;
			virtual void Shutdown() = 0;
			virtual std::string const& GetName() const { return m_name; }

		protected:

			Service();

			void SetName(std::string name);

		private:
			std::string m_name;
		};
	}
}



