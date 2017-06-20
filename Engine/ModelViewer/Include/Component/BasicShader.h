#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdint>
#include <string>

class BasicShader
{
	public:
		BasicShader();
		~BasicShader();

		void LoadAndCreateShaders(std::string const& vertexShader, std::string const& fragmentShader);
		bool LoadShader(uint32_t type, const char* path);
		bool Create();

		void Destroy();

		void Bind();
		void Unbind();

		inline
			uint32_t Get() { return m_Program; }

		inline void SetLinkCallback(void(*func)(int)) {LinkCallback = func;}

	private:

		void(*LinkCallback)(int);

		uint32_t m_VertexShader;
		uint32_t m_FragmentShader;
		uint32_t m_GeometryShader;
		uint32_t m_Program;
		uint32_t m_ComputeShader;
		uint32_t m_ControlShader;
		uint32_t m_EvaluationShader;
};

