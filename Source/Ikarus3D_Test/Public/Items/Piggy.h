// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Piggy.generated.h"

UCLASS()
class IKARUS3D_TEST_API APiggy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APiggy();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	class UStaticMeshComponent* Piggy;
	UFUNCTION()
	void OnMeshHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleSystem")
	UParticleSystemComponent* ParticleSystemComponent;
	UPROPERTY(EditDefaultsOnly)
	USoundBase* HitSound;
	// DoOnce node to ensure sound is played only once
	bool DoOnce = true;
	void DestroyActorDelayed();
};
