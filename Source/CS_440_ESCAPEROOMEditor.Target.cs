// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CS_440_ESCAPEROOMEditorTarget : TargetRules
{
	public CS_440_ESCAPEROOMEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "CS_440_ESCAPEROOM" } );
	}
}
