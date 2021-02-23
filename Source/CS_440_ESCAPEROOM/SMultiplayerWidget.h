// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class CS_440_ESCAPEROOM_API SMultiplayerWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMultiplayerWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
};
