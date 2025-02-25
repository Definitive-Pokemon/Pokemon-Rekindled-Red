TohjoFalls_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TohjoFalls_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, TohjoFalls_OnTransition
	.byte 0

TohjoFalls_OnLoad::
	compare VAR_CHANGEFALLS, 1
	goto_if_eq TohjoFalls_EventScript_RegularFalls
	end

TohjoFalls_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_TOHJO_FALLS
	end

TohjoFalls_EventScript_RegularFalls::
    setvar VAR_CHANGEFALLS, 1
	setmetatile 14, 14, METATILE_General_Waterfall, 0
	setmetatile 15, 14, METATILE_General_Waterfall, 0
	setmetatile 16, 14, METATILE_General_Waterfall, 0
	setmetatile 17, 14, METATILE_General_Waterfall, 0
	setmetatile 18, 14, METATILE_General_Waterfall, 0
	setmetatile 14, 15, METATILE_General_Waterfall, 0
	setmetatile 15, 15, METATILE_General_Waterfall, 0
	setmetatile 16, 15, METATILE_General_Waterfall, 0
	setmetatile 17, 15, METATILE_General_Waterfall, 0
	setmetatile 18, 15, METATILE_General_Waterfall, 0
	setmetatile 14, 16, METATILE_General_Waterfall, 0
	setmetatile 15, 16, METATILE_General_Waterfall, 0
	setmetatile 16, 16, METATILE_General_Waterfall, 0
	setmetatile 17, 16, METATILE_General_Waterfall, 0
	setmetatile 18, 16, METATILE_General_Waterfall, 0
	setmetatile 14, 17, METATILE_General_Waterfall, 0
	setmetatile 15, 17, METATILE_General_Waterfall, 0
	setmetatile 16, 17, METATILE_General_Waterfall, 0
	setmetatile 17, 17, METATILE_General_Waterfall, 0
	setmetatile 18, 17, METATILE_General_Waterfall, 0
	setmetatile 14, 18, METATILE_General_Waterfall, 0
	setmetatile 15, 18, METATILE_General_Waterfall, 0
	setmetatile 16, 18, METATILE_General_Waterfall, 0
	setmetatile 17, 18, METATILE_General_Waterfall, 0
	setmetatile 18, 18, METATILE_General_Waterfall, 0
	setmetatile 14, 19, METATILE_General_Waterfall, 0
	setmetatile 15, 19, METATILE_General_Waterfall, 0
	setmetatile 16, 19, METATILE_General_Waterfall, 0
	setmetatile 17, 19, METATILE_General_Waterfall, 0
	setmetatile 18, 19, METATILE_General_Waterfall, 0
	setmetatile 14, 20, METATILE_General_Waterfall, 0
	setmetatile 15, 20, METATILE_General_Waterfall, 0
	setmetatile 16, 20, METATILE_General_Waterfall, 0
	setmetatile 17, 20, METATILE_General_Waterfall, 0
	setmetatile 18, 20, METATILE_General_Waterfall, 0
	setmetatile 26, 14, METATILE_General_Waterfall, 0
	setmetatile 27, 14, METATILE_General_Waterfall, 0
	setmetatile 28, 14, METATILE_General_Waterfall, 0
	setmetatile 29, 14, METATILE_General_Waterfall, 0
	setmetatile 30, 14, METATILE_General_Waterfall, 0
	setmetatile 26, 15, METATILE_General_Waterfall, 0
	setmetatile 27, 15, METATILE_General_Waterfall, 0
	setmetatile 28, 15, METATILE_General_Waterfall, 0
	setmetatile 29, 15, METATILE_General_Waterfall, 0
	setmetatile 30, 15, METATILE_General_Waterfall, 0
	setmetatile 26, 16, METATILE_General_Waterfall, 0
	setmetatile 27, 16, METATILE_General_Waterfall, 0
	setmetatile 28, 16, METATILE_General_Waterfall, 0
	setmetatile 29, 16, METATILE_General_Waterfall, 0
	setmetatile 30, 16, METATILE_General_Waterfall, 0
	setmetatile 26, 17, METATILE_General_Waterfall, 0
	setmetatile 27, 17, METATILE_General_Waterfall, 0
	setmetatile 28, 17, METATILE_General_Waterfall, 0
	setmetatile 29, 17, METATILE_General_Waterfall, 0
	setmetatile 30, 17, METATILE_General_Waterfall, 0
	setmetatile 26, 18, METATILE_General_Waterfall, 0
	setmetatile 27, 18, METATILE_General_Waterfall, 0
	setmetatile 28, 18, METATILE_General_Waterfall, 0
	setmetatile 29, 18, METATILE_General_Waterfall, 0
	setmetatile 30, 18, METATILE_General_Waterfall, 0
	setmetatile 26, 19, METATILE_General_Waterfall, 0
	setmetatile 27, 19, METATILE_General_Waterfall, 0
	setmetatile 28, 19, METATILE_General_Waterfall, 0
	setmetatile 29, 19, METATILE_General_Waterfall, 0
	setmetatile 30, 19, METATILE_General_Waterfall, 0
	setmetatile 26, 20, METATILE_General_Waterfall, 0
	setmetatile 27, 20, METATILE_General_Waterfall, 0
	setmetatile 28, 20, METATILE_General_Waterfall, 0
	setmetatile 29, 20, METATILE_General_Waterfall, 0
	setmetatile 30, 20, METATILE_General_Waterfall, 0
	special DrawWholeMapView
	end

TohjoFalls_EventScript_UnderFalls::
	setvar VAR_CHANGEFALLS, 0
	setmetatile 14, 14, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 15, 14, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 16, 14, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 17, 14, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 18, 14, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 14, 15, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 15, 15, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 16, 15, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 17, 15, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 18, 15, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 14, 16, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 15, 16, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 16, 16, METATILE_RockTunnel_DoorUnderWaterfall, 0
	setmetatile 17, 16, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 18, 16, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 14, 17, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 15, 17, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 16, 17, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 17, 17, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 18, 17, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 14, 18, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 15, 18, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 16, 18, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 17, 18, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 18, 18, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 14, 19, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 15, 19, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 16, 19, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 17, 19, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 18, 19, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 14, 20, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 15, 20, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 16, 20, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 17, 20, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 18, 20, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 26, 14, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 27, 14, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 28, 14, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 29, 14, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 30, 14, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 26, 15, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 27, 15, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 28, 15, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 29, 15, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 30, 15, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 26, 16, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 27, 16, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 28, 16, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 29, 16, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 30, 16, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 26, 17, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 27, 17, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 28, 17, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 29, 17, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 30, 17, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 26, 18, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 27, 18, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 28, 18, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 29, 18, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 30, 18, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 26, 19, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 27, 19, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 28, 19, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 29, 19, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 30, 19, METATILE_RockTunnel_UnderWaterfall, 1
	setmetatile 26, 20, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 27, 20, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 28, 20, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 29, 20, METATILE_RockTunnel_UnderWaterfall, 0
	setmetatile 30, 20, METATILE_RockTunnel_UnderWaterfall, 0
	special DrawWholeMapView
	end
	