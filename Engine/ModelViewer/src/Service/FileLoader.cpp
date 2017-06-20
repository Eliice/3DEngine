#include "Service\FileLoader.h"

#include <fstream>

#include "Service\servicelocator.h"

namespace tools
{
	namespace service
	{
		FileLoader::FileLoader()
		{
			Initialize();
		}


		FileLoader::~FileLoader()
		{
		}

		void FileLoader::Initialize()
		{
			std::string name = "FileLoader";
			SetName(name);
		}

		void FileLoader::Shutdown()
		{
		}

		std::string FileLoader::LoadFile(std::string const & path)
		{
			
			std::ifstream* file = new std::ifstream(path);
			if (file->is_open())
			{
				std::string content = std::string();
				std::string lineBuffer ;
				while (getline(*file,lineBuffer))
				{
					content += lineBuffer;
					content += '\n';
				}
				file->close();
				return content;
			}
			else
			{
				std::string error = "can't open fail" + path;
				LOGGER->Debuglog(error, LogLevel::WARNING);
				return "";
			}
		}

		std::string FileLoader::LoadFile(char * const path)
		{
			std::ifstream* file = new std::ifstream(path);
			if (file->is_open())
			{
				std::string content = std::string();
				std::string lineBuffer;
				while (getline(*file, lineBuffer))
				{
					content += lineBuffer;
					content += '\n';

				}
				file->close();
				return content;
			}
			else
			{
				std::string error = "can't open file ";
				error.append(path);
				LOGGER->Debuglog(error, LogLevel::WARNING);
				return "";
			}
		}
		void FileLoader::Write(std::string data, std::string path)
		{
			std::ofstream file;
			file.open(path);
			file << data;
			file.close();
		}
	}
}

