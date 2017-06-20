#pragma once

#include <string>
#include "Service.h"

namespace tools
{
	namespace service
	{
		class FileLoader final : public Service
		{
		public:

			FileLoader();
			~FileLoader();

			void Initialize();
			void Shutdown();

			std::string LoadFile(std::string const&);
			std::string LoadFile(char* const);
			void Write(std::string data, std::string path);
		};
	}
}

