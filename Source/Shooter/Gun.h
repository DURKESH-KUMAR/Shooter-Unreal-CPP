#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	AGun();
	void PullTrigger();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(VisibleAnyWhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere)
	UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere)
	float MaxRange=1000;

	UPROPERTY(EditAnywhere)
	float Damage=10;
};
