// Fill out your copyright notice in the Description page of Project Settings.


#include "AwardCharacter2.h"
#include "GameFramework/DefaultPawn.h"
#include "Components/InputComponent.h"

// Sets default values
AAwardCharacter2::AAwardCharacter2()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void AAwardCharacter2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAwardCharacter2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

// Called to bind functionality to input
void AAwardCharacter2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AAwardCharacter2::Attack_Melee);

}

void AAwardCharacter2::Attack_Melee()
{
	PlayAnimMontage(AttackAnim, 1.0f);
}