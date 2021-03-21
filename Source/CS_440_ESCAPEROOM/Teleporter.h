// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Teleporter.generated.h"

UCLASS()
class CS_440_ESCAPEROOM_API ATeleporter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleporter();
	UPROPERTY(EditAnyWhere)
	class UBoxComponent* CollisionBox;

	//UFUNCTION()
	//	void EnterTeleporter(class AActor* overlappedActor, class AActor* otherActor);
	//UFUNCTION()
	//	void ExitTeleporter(class AActer* overlappedActer, class AActor* otherActor);
	//UPROPERTY(EditAnywhere, Category = "Teleporter")
	//	ATeleporter* otherTele;
	//UPROPERTY()
	//	bool teleporting;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, Category = "Teleport point")
	FVector CustomUserValue;
	UFUNCTION()
		virtual void OnComponentBeginOverlap(
			UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Returns CollectionSPhere subobject 
	FORCEINLINE class UBoxComponent* GetCollisionBox() const { return CollisionBox; }
};
