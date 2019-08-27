#pragma once
#include "HashMap.hpp"
#include "Swallow/Renderer/Texture.hpp"

#include "swpch.hpp"
namespace SwallowEngine
{
	enum ResourceType
	{
		NONE = 0,
		TEXTURES,
		MODELS,
		SOUNDS,
		MISC
	};

	class AssestManager
	{
	public:
		AssestManager();
		AssestManager(const AssestManager&) = default;
		AssestManager &operator=(const AssestManager&) = default;
		~AssestManager();

		template <typename T>
		T* findResource(ResourceType, std::string);

		template <typename T>
		void	addResource(ResourceType, std::string, T);

	private:
		HashMap<std::shared_ptr<Swallow::Texture>>* m_Textures;
		HashMap<bool>* m_Models;
		HashMap<bool>* m_Sounds;
		HashMap<bool>* m_Misc;
	};
}


