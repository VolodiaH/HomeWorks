
#pragma once
#include <vector>

#include <memory>
#include "Modifier.h"
#include "MyAlgorithm.h"

class ModifierDeck
{
public:
	ModifierDeck();

	Modifier* generateModifier();

	std::vector<Modifier*> generateModifiers()  { return algorithm::castToVectorRawPtr(m_modifiersDatabase); }

private:
	Modifier *createRandomModifier();
	std::vector<std::unique_ptr<Modifier>> m_modifiersDatabase;
};