// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMainCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookSide"), this, &AMainCharacter::LookSide);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this,  &AMainCharacter::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AMainCharacter::CharacterJump);

}

void AMainCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AMainCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector()*AxisValue);
}

void AMainCharacter::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void AMainCharacter::LookSide(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void AMainCharacter::CharacterJump()
{
	ACharacter::Jump();
}

