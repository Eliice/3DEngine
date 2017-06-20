#include "Libraries\Library.h"
#include "Service\servicelocator.h"


Library::Library(std::string const& name, Library* parent)
	: m_Name(name)
{
	m_Parent = parent;
}


Library::~Library()
{
	std::unordered_map<std::string, Library*>::iterator iter = m_SubLibraries.begin();
	std::unordered_map<std::string, Library*>::iterator end = m_SubLibraries.end();

	while (iter != end)
	{
		delete iter->second;
		++iter;
	}

	m_SubLibraries.clear();
}

void Library::Initialize()
{
	if (!m_Parent)
		LIBRARY_MANAGER->RegisterLibrary(this);

	std::unordered_map<std::string, Library*>::iterator iter = m_SubLibraries.begin();
	std::unordered_map<std::string, Library*>::iterator end = m_SubLibraries.end();

	while (iter != end)
	{
		iter->second->Initialize();
		++iter;
	}
}

void Library::Shutdown()
{
	std::unordered_map<std::string, Library*>::iterator iter = m_SubLibraries.begin();
	std::unordered_map<std::string, Library*>::iterator end = m_SubLibraries.end();

	while (iter != end)
		iter->second->Shutdown();
}

void Library::AddSubLibrary(Library* newLib)
{
	if (!newLib)
		return;

	std::string name = newLib->GetName();
	std::unordered_map<std::string, Library*>::iterator iter = m_SubLibraries.find(name);

	if (iter == m_SubLibraries.end())
		m_SubLibraries[name] = newLib;
	else
		ERROR_MANAGER->Fatal("Sub Library " + m_Name + " already exists");
}

void Library::Update()
{
	std::unordered_map<std::string, Library*>::iterator iter = m_SubLibraries.begin();
	std::unordered_map<std::string, Library*>::iterator end = m_SubLibraries.end();

	while (iter != end)
		iter->second->Update();
}