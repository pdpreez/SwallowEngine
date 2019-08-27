#include "swpch.hpp"
#include "AssestManager.hpp"

namespace Swallow
{
	AssestManager::AssestManager()
	{

		m_Textures = new HashMap<std::shared_ptr<Texture>>();
		m_Models = new HashMap<bool>();
		m_Sounds = new HashMap<bool>();
		m_Misc = new HashMap<bool>();
	}

	AssestManager::~AssestManager()
	{
		delete m_Textures;
		delete m_Models;
		delete m_Sounds;
		delete m_Misc;
	}

	template <typename T>
	void AssestManager::addResource(ResourceType type, std::string name, T value)
	{
		switch (type)
		{
		case ResourceType::NONE:
		default:
			break;
		case ResourceType::TEXTURES:
			m_Textures->put(name, value);
			break;
		case ResourceType::MODELS:
			m_Models->put(name, value);
			break;
		case ResourceType::SOUNDS:
			m_Sounds->put(name, value);
			break;
		case ResourceType::MISC:
			m_Misc->put(name, value);
			break;
		}
	}

	template <typename T>
	T* AssestManager::findResource(ResourceType type, std::string name)
	{
		return nullptr;
		switch (type)
		{
		case ResourceType::NONE:
		default:
			return nullptr;
		case ResourceType::TEXTURES:
			return (T*)m_Textures->get(name);
		case ResourceType::MODELS:
			return (T*)m_Models->get(name);
		case ResourceType::SOUNDS:
			return (T*)m_Sounds->get(name);
		case ResourceType::MISC:
			return (T*)m_Misc->get(name);
		}
	}
}