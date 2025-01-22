#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CMovementComponent.generated.h"

UENUM()
enum class ESpeed : uint8
{
	Crouch = 0, Stand, MAX
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ODYSSEY_API UCMovementComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Speed")
	float Speed[(int32)ESpeed::MAX] = { 150, 300 };

public:
	FORCEINLINE bool CanMove() { return bCanMove; }
	FORCEINLINE void Move() { bCanMove = true; }
	FORCEINLINE void Stop() { bCanMove = false; }

	FORCEINLINE float GetStandSpeed() { return Speed[(int32)ESpeed::Stand]; }

	FORCEINLINE bool GetFixedCamera() { return bFixedCamera; }
	FORCEINLINE void EnableFixedCamera() { bFixedCamera = true; }
	FORCEINLINE void DisableFixedCamera() { bFixedCamera = false; }

public:	
	UCMovementComponent();

protected:
	virtual void BeginPlay() override;

public:
	void EnableControlRotation();
	void DisableControlRotation();

public:
	void OnMovement(const struct FInputActionValue& InVal);
	void OnLook(const struct FInputActionValue& InVal);

private:
	class ACCharacter* Owner;

private:
	bool bCanMove = true;
	bool bCrouch = false;
	bool bCanSprint = false;
	bool bFixedCamera;

public:
	bool IsCrouch() { return bCrouch; }
};
