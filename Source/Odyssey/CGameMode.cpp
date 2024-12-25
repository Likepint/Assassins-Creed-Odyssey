#include "CGameMode.h"

ACGameMode::ACGameMode()
{
	ConstructorHelpers::FClassFinder<APawn> pawn(L"/Script/Engine.Blueprint'/Game/Characters/BP_CCharacter.BP_CCharacter_C'");

	if (pawn.Succeeded())
		DefaultPawnClass = pawn.Class;

}
