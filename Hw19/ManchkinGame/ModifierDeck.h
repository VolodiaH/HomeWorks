
#pragma once
#include <vector>

#include <memory>
#include "Modifier.h"
#include "MyAlgorithm.h"

class ModifierDeck
{
public:
	
	static ModifierDeck &instance();
	Modifier* generateModifier();

	std::vector<Modifier*> generateModifiers()  { return algorithm::castToVectorRawPtr(m_modifiersDatabase); }

private:

	ModifierDeck();
	Modifier *createRandomModifier();
	std::vector<std::unique_ptr<Modifier>> m_modifiersDatabase;
};