#include "Components/CMovementComponent.h"
#include "Global.h"
#include "Characters/CCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputActionValue.h"

UCMovementComponent::UCMovementComponent()
{

}

void UCMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = Cast<ACCharacter>(GetOwner());
}

void UCMovementComponent::EnableControlRotation()
{
	Owner->bUseControllerRotationYaw = true;
	Owner->GetCharacterMovement()->bOrientRotationToMovement = false;
}

void UCMovementComponent::DisableControlRotation()
{
	Owner->bUseControllerRotationYaw = false;
	Owner->GetCharacterMovement()->bOrientRotationToMovement = true;
}

void UCMovementComponent::OnMovement(const FInputActionValue& InVal)
{	
	FalseCheck(bCanMove);

	FRotator rotator = FRotator(0, Owner->GetControlRotation().Yaw, 0);

	// Forward
	Owner->AddMovementInput(FQuat(rotator).GetForwardVector(), InVal.Get<FVector2D>().X);

	// Right
	Owner->AddMovementInput(FQuat(rotator).GetRightVector(), InVal.Get<FVector2D>().Y);
}

void UCMovementComponent::OnLook(const FInputActionValue& InVal)
{
	// Horizontal
	Owner->AddControllerYawInput(InVal.Get<FVector2D>().X * 0.5);

	// Vertical
	Owner->AddControllerPitchInput(InVal.Get<FVector2D>().Y * 0.5);
}
