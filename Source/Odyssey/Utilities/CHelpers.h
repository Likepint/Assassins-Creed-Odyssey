#pragma once

#include "CoreMinimal.h"

class ODYSSEY_API CHelpers
{
public:
	template<typename T>
	static void CreateComponent(AActor* InActor, T** OutComponent, FName InName, USceneComponent* InParent = nullptr, FName InSocketName = NAME_None)
	{
		*OutComponent = InActor->CreateDefaultSubobject<T>(InName);

		if (!!InParent)
		{
			(*OutComponent)->SetupAttachment(InParent, InSocketName);

			return;
		}

		InActor->SetRootComponent(*OutComponent);
	}
};
