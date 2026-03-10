#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class SHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AShooterCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount,struct FDamageEvent const &DamageEvent,class AController *EventInstigator,AActor *DamageCauser) override;
	
	void Shoot();
		
private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth=100;

	UPROPERTY(VisibleAnywhere)
	float Health;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun;
};
