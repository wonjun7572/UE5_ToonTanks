// Fill out your copyright notice in the Description page of Project Settings.

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"

ATank::ATank()
{
     m_SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
     m_SpringArm->SetupAttachment(RootComponent);

     m_Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
     m_Camera->SetupAttachment(m_SpringArm);
}

void ATank::Move(float Value)
{
     FVector DeltaLocation(0.f);
     // X = Value * DeltaTime * Speed
	DeltaLocation.X = Value * UGameplayStatics::GetWorldDeltaSeconds(this) * m_fSpeed;
	AddActorLocalOffset(DeltaLocation);
}

void ATank::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
     Super::SetupPlayerInputComponent(PlayerInputComponent);

     PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
}