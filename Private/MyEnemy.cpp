// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnemy.h"
#include "Perception/PawnSensingComponent.h"
#include "Engine.h"
#include "MyEnemyAIController.h"
#include "AwardCharacter2.h"

// Sets default values
AMyEnemy::AMyEnemy()
{
    PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
    // “GƒLƒƒƒ‰‚ÌŽ‹–ì
    PawnSensingComp->SetPeripheralVisionAngle(60.0f);
    // “GƒLƒƒƒ‰‚ÌŒ©‚é‚±‚Æ‚Ì‚Å‚«‚é”ÍˆÍ
    PawnSensingComp->SightRadius = 2000;
    PawnSensingComp->OnSeePawn.AddDynamic(this, &AMyEnemy::OnSeePlayer);

}

void AMyEnemy::OnSeePlayer(APawn* Pawn)
{
    AMyEnemyAIController* AIController = Cast<AMyEnemyAIController>(GetController());
    AAwardCharacter2* Player = Cast<AAwardCharacter2>(Pawn);
    if (AIController && Player)
    {
        AIController->SetPlayerActorKey(Player);
    }
}

// Called when the game starts or when spawned
void AMyEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

