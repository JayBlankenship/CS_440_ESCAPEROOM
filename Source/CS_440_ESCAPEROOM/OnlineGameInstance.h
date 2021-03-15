// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CS_440_ESCAPEROOM_API UOnlineGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UOnlineGameInstance();
	
protected:
	IOnlineSessionPtr session;

	virtual void OnCreateSessionComplete(FName serverName, bool succeeded);

	virtual void Init() override;

	UFUNCTION(BlueprintCallable)
		void Host();
	UFUNCTION(BlueprintCallable)
		void JoinServer();


	void EndServer();

};
