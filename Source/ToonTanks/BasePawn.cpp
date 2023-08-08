// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/CapsuleComponent.h"
#include "BasePawn.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule Collider");
	RootComponent = m_CapsuleComponent;

	m_BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("Base Mesh");
	m_BaseMesh->SetupAttachment(m_CapsuleComponent);

	m_TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>("Turret Mesh");
	m_TurretMesh->SetupAttachment(m_BaseMesh);

	m_ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>("Spawn Point");
	m_ProjectileSpawnPoint->SetupAttachment(m_TurretMesh);
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}