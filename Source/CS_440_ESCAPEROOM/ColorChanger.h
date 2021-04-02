// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "ColorChanger.generated.h"

UCLASS()
class CS_440_ESCAPEROOM_API AColorChanger : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnyWhere)
	class UBoxComponent* CollisionBox;
	// Sets default values for this actor's properties
	AColorChanger();
	UPROPERTY(EditAnywhere, Category = "COLOR")
		UMaterialInterface* CustomUserValue;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
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
