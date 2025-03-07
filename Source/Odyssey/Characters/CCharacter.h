#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CCharacter.generated.h"

UCLASS()
class ODYSSEY_API ACCharacter : public ACharacter
{
	GENERATED_BODY()

private: // Components
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	class UCMovementComponent* Movement;

private: // Enhanced Input
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputMappingContext* DefaultContext;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* IA_Movement;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* IA_Look;

public:
	ACCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void Initialize();
	void SetEnhancedInput();
};
