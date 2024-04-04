// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWeaponActor.h"
#include "Components/BoxComponent.h"
#include "Engine.h"

// Sets default values
AMyWeaponActor::AMyWeaponActor(const class FObjectInitializer& ObjectInitializer)//:Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WeaponMesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("WeaponMesh"));
	WeaponMesh->CastShadow = true;
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = WeaponMesh;

	WeaponCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollision"));
	WeaponCollision->SetBoxExtent(FVector(5.f, 5.f, 5.f));
	WeaponCollision->AttachTo(WeaponMesh, "DamageSocket");


	static ConstructorHelpers::FObjectFinder<UParticleSystem>ParticleAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	HitFX = ParticleAsset.Object;
}

void AMyWeaponActor::SetOwningPawn(AMyBasicCharacter* NewOwner)
{
	if (MyPawn != NewOwner)
	{
		MyPawn = NewOwner;
	}
}



void AMyWeaponActor::AttachMeshToPawn()
{
	if (MyPawn)
	{
		USkeletalMeshComponent* PawnMesh = MyPawn->GetSpesificPawnMesh();
		FName AttachPoint = MyPawn->GetWeaponAttachPoint();
		WeaponMesh->AttachTo(PawnMesh, AttachPoint);
	}

}

void AMyWeaponActor::OnEquip(const AMyWeaponActor* LastWeapon)
{
	AttachMeshToPawn();
}

// Called when the game starts or when spawned
void AMyWeaponActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyWeaponActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyWeaponActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (OtherActor->IsA(AActor::StaticClass()) && MyPawn->isDuringAttack && OtherActor != MyPawn)
	{
		UGameplayStatics::ApplyDamage(OtherActor, 30.f, NULL, this, UDamageType::StaticClass());
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "ApplyDamage!");

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitFX, GetActorLocation());
	}
}