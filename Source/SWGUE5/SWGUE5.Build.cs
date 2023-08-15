// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SWGUE5 : ModuleRules
{
	public SWGUE5(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
