// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "characterpawn.generated.h"


UCLASS()
class CS_440_ESCAPEROOM_API Acharacterpawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	Acharacterpawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		float ImpulseForceJump;
	UPROPERTY(EditAnywhere)
		float ImpulseForceMove;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* VisibleComponent;

	UPROPERTY(EditAnywhere)
		USpringArmComponent* OurCameraSpringArm;

	UPROPERTY(EditAnywhere)
		UCameraComponent* OurCamera;

	UPROPERTY(EditAnywhere)
		USceneComponent* RotatorComponent;

	UPROPERTY(EditAnywhere)
		USceneComponent* ConnectionComponent;

	void movecameraupordown(float input);
	void movecamerside2side(float input);
	void MoveForward(float input);
	void MoveRight(float input);
	void jumpup();


};
