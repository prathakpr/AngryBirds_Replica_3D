// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Sling.h"
#include "Camera/CameraComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"

// Sets default values
ASling::ASling()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = DefaultSceneRoot;
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	MyBillboardComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("MyBillboard"));
	MyStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));
	MyArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("MyArrow"));

}

// Called when the game starts or when spawned
void ASling::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASling::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASling::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

