#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Engine/DamageEvents.h"

AGun::AGun()
{
	PrimaryActorTick.bCanEverTick = true;

	Root=CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh=CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

void AGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash,Mesh,TEXT("b_gun_muzzleflash"));

	APawn* OwnerPawn=Cast<APawn>(GetOwner());
	if(OwnerPawn==nullptr)return;
	AController* OwnerController=OwnerPawn->GetController();
	if(OwnerController==nullptr)return;
    FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location,Rotation);
	FVector End=Location+Rotation.Vector()*MaxRange;
	// DrawDebugCamera(GetWorld(),Location,Rotation,90,2,FColor::Red,true);
	FHitResult Hit;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	bool bSuccess=GetWorld()->LineTraceSingleByChannel(Hit,Location,End,ECollisionChannel::ECC_GameTraceChannel1,Params);
	
	if(bSuccess)
	{
		FVector ShotDirection=-Rotation.Vector();
		// DrawDebugPoint(GetWorld(),Hit.Location,20,FColor::Red,true);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ImpactEffect,Hit.Location,ShotDirection.Rotation());
		AActor* HitActor=Hit.GetActor();
		if(HitActor!=nullptr)
		{
			FPointDamageEvent DamageEvent(Damage,Hit,ShotDirection,nullptr);
			HitActor->TakeDamage(Damage,DamageEvent,OwnerController,this);
		}
	}

}

void AGun::BeginPlay()
{
	Super::BeginPlay();
}

void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

