// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuHUD.h"
#include "SMainMenuWidget.h"
#include "Engine.h"

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine && GEngine->GameViewport) {
		MainMenuWidget = SNew(SMainMenuWidget).OwnerHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(MainMenuWidget.ToSharedRef()));
		MainMenuWidget->SetVisibility(EVisibility::Visible);
	}
}
