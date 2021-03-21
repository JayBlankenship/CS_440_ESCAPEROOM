// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "slidingdoorplusvolume.generated.h"

UCLASS()
class CS_440_ESCAPEROOM_API Aslidingdoorplusvolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aslidingdoorplusvolume();
	
	UPROPERTY(EditAnyWhere)
	class UBoxComponent* CollisionBox;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* VisibleComponent;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//UFUNCTION()
		
public:	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* VisibleComponenttobemoved;
	UPROPERTY(EditAnywhere, Category = "Menus")
	float CustomUserValue;
	UPROPERTY(EditAnywhere, Category = "Menus")
	FString CustomUserchar;
	bool opendoorb;
	void opendoor();
	UFUNCTION()
	virtual void OnComponentBeginOverlap(
			UPrimitiveComponent* OverlappedComp, 
			AActor* OtherActor, 
			UPrimitiveComponent* OtherComp, 
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

	//virtual void WasCollected_Implementation();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Returns CollectionSPhere subobject 
	FORCEINLINE class UBoxComponent* GetCollisionBox() const { return CollisionBox; }

};
