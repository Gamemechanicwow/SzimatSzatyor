/*
 * This file is part of SzimatSzatyor.
 *
 * SzimatSzatyor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * SzimatSzatyor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with SzimatSzatyor.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <ctime>

// this class encapsulates functions which logging the packets
class PacketDump
{
public:
    enum PacketType
    {
        PACKET_TYPE_C2S = 0, // client to server, CMSG
        PACKET_TYPE_S2C = 1  // server to client, SMSG
    };

    enum UserFiendlyLogStatus
    {
        USER_FRIENDLY_LOG_NOT_CHECKED,
        USER_FRIENDLY_LOG_DISABLED,
        USER_FRIENDLY_LOG_ENABLED
    };

    // name of the file which enables the "user friendly" log format
    static char enableUserFriendlyFileName[];
    // path of the file which enables the "user friendly" log format
    static char enableUserFriendlyPath[MAX_PATH];

    static FILE* userFriendlyDumpFile;
    static FILE* binaryDumpFile;

private:
    static UserFiendlyLogStatus _userFiendlyLogStatus;

    static char* getopcodename(DWORD t)
    {
        char* r;
        switch (t) {
            case 0x000: r = "MSG_NULL_ACTION"; break;
            case 0x001: r = "CMSG_BOOTME"; break;
            case 0x002: r = "CMSG_DBLOOKUP"; break;
            case 0x003: r = "SMSG_DBLOOKUP"; break;
            case 0x004: r = "CMSG_QUERY_OBJECT_POSITION"; break;
            case 0x005: r = "SMSG_QUERY_OBJECT_POSITION"; break;
            case 0x006: r = "CMSG_QUERY_OBJECT_ROTATION"; break;
            case 0x007: r = "SMSG_QUERY_OBJECT_ROTATION"; break;
            case 0x008: r = "CMSG_WORLD_TELEPORT"; break;
            case 0x009: r = "CMSG_TELEPORT_TO_UNIT"; break;
            case 0x00a: r = "CMSG_ZONE_MAP"; break;
            case 0x00b: r = "SMSG_ZONE_MAP"; break;
            case 0x00c: r = "CMSG_DEBUG_CHANGECELLZONE"; break;
            case 0x00d: r = "CMSG_EMBLAZON_TABARD_OBSOLETE"; break;
            case 0x00e: r = "CMSG_UNEMBLAZON_TABARD_OBSOLETE"; break;
            case 0x00f: r = "CMSG_RECHARGE"; break;

            case 0x010: r = "CMSG_LEARN_SPELL"; break;
            case 0x011: r = "CMSG_CREATEMONSTER"; break;
            case 0x012: r = "CMSG_DESTROYMONSTER"; break;
            case 0x013: r = "CMSG_CREATEITEM"; break;
            case 0x014: r = "CMSG_CREATEGAMEOBJECT"; break;
            case 0x015: r = "SMSG_CHECK_FOR_BOTS"; break;
            case 0x016: r = "CMSG_MAKEMONSTERATTACKGUID"; break;
            case 0x017: r = "CMSG_BOT_DETECTED2"; break;
            case 0x018: r = "CMSG_FORCEACTION"; break;
            case 0x019: r = "CMSG_FORCEACTIONONOTHER"; break;
            case 0x01a: r = "CMSG_FORCEACTIONSHOW"; break;
            case 0x01b: r = "SMSG_FORCEACTIONSHOW"; break;
            case 0x01c: r = "CMSG_PETGODMODE"; break;
            case 0x01d: r = "SMSG_PETGODMODE"; break;
            case 0x01e: r = "SMSG_DEBUGINFOSPELLMISS_OBSOLETE"; break;
            case 0x01f: r = "CMSG_WEATHER_SPEED_CHEAT"; break;

            case 0x020: r = "CMSG_UNDRESSPLAYER"; break;
            case 0x021: r = "CMSG_BEASTMASTER"; break;
            case 0x022: r = "CMSG_GODMODE"; break;
            case 0x023: r = "SMSG_GODMODE"; break;
            case 0x024: r = "CMSG_CHEAT_SETMONEY"; break;
            case 0x025: r = "CMSG_LEVEL_CHEAT"; break;
            case 0x026: r = "CMSG_PET_LEVEL_CHEAT"; break;
            case 0x027: r = "CMSG_SET_WORLDSTATE"; break;
            case 0x028: r = "CMSG_COOLDOWN_CHEAT"; break;
            case 0x029: r = "CMSG_USE_SKILL_CHEAT"; break;
            case 0x02a: r = "CMSG_FLAG_QUEST"; break;
            case 0x02b: r = "CMSG_FLAG_QUEST_FINISH"; break;
            case 0x02c: r = "CMSG_CLEAR_QUEST"; break;
            case 0x02d: r = "CMSG_SEND_EVENT"; break;
            case 0x02e: r = "CMSG_DEBUG_AISTATE"; break;
            case 0x02f: r = "SMSG_DEBUG_AISTATE"; break;

            case 0x030: r = "CMSG_DISABLE_PVP_CHEAT"; break;
            case 0x031: r = "CMSG_ADVANCE_SPAWN_TIME"; break;
            case 0x032: r = "CMSG_PVP_PORT_OBSOLETE"; break;
            case 0x033: r = "CMSG_AUTH_SRP6_BEGIN"; break;
            case 0x034: r = "CMSG_AUTH_SRP6_PROOF"; break;
            case 0x035: r = "CMSG_AUTH_SRP6_RECODE"; break;
            case 0x036: r = "CMSG_CHAR_CREATE"; break;
            case 0x037: r = "CMSG_CHAR_ENUM"; break;
            case 0x038: r = "CMSG_CHAR_DELETE"; break;
            case 0x039: r = "SMSG_AUTH_SRP6_RESPONSE"; break;
            case 0x03a: r = "SMSG_CHAR_CREATE"; break;
            case 0x03b: r = "SMSG_CHAR_ENUM"; break;
            case 0x03c: r = "SMSG_CHAR_DELETE"; break;
            case 0x03d: r = "CMSG_PLAYER_LOGIN"; break;
            case 0x03e: r = "SMSG_NEW_WORLD"; break;
            case 0x03f: r = "SMSG_TRANSFER_PENDING"; break;

            case 0x040: r = "SMSG_TRANSFER_ABORTED"; break;
            case 0x041: r = "SMSG_CHARACTER_LOGIN_FAILED"; break;
            case 0x042: r = "SMSG_LOGIN_SETTIMESPEED"; break;
            case 0x043: r = "SMSG_GAMETIME_UPDATE"; break;
            case 0x044: r = "CMSG_GAMETIME_SET"; break;
            case 0x045: r = "SMSG_GAMETIME_SET"; break;
            case 0x046: r = "CMSG_GAMESPEED_SET"; break;
            case 0x047: r = "SMSG_GAMESPEED_SET"; break;
            case 0x048: r = "CMSG_SERVERTIME"; break;
            case 0x049: r = "SMSG_SERVERTIME"; break;
            case 0x04a: r = "CMSG_PLAYER_LOGOUT"; break;
            case 0x04b: r = "CMSG_LOGOUT_REQUEST"; break;
            case 0x04c: r = "SMSG_LOGOUT_RESPONSE"; break;
            case 0x04d: r = "SMSG_LOGOUT_COMPLETE"; break;
            case 0x04e: r = "CMSG_LOGOUT_CANCEL"; break;
            case 0x04f: r = "SMSG_LOGOUT_CANCEL_ACK"; break;


            case 0x050: r = "CMSG_NAME_QUERY"; break;
            case 0x051: r = "SMSG_NAME_QUERY_RESPONSE"; break;
            case 0x052: r = "CMSG_PET_NAME_QUERY"; break;
            case 0x053: r = "SMSG_PET_NAME_QUERY_RESPONSE"; break;
            case 0x054: r = "CMSG_GUILD_QUERY"; break;
            case 0x055: r = "SMSG_GUILD_QUERY_RESPONSE"; break;
            case 0x056: r = "CMSG_ITEM_QUERY_SINGLE"; break;
            case 0x057: r = "CMSG_ITEM_QUERY_MULTIPLE"; break;
            case 0x058: r = "SMSG_ITEM_QUERY_SINGLE_RESPONSE"; break;
            case 0x059: r = "SMSG_ITEM_QUERY_MULTIPLE_RESPONSE"; break;
            case 0x05a: r = "CMSG_PAGE_TEXT_QUERY"; break;
            case 0x05b: r = "SMSG_PAGE_TEXT_QUERY_RESPONSE"; break;
            case 0x05c: r = "CMSG_QUEST_QUERY"; break;
            case 0x05d: r = "SMSG_QUEST_QUERY_RESPONSE"; break;
            case 0x05e: r = "CMSG_GAMEOBJECT_QUERY"; break;
            case 0x05f: r = "SMSG_GAMEOBJECT_QUERY_RESPONSE"; break;

            case 0x060: r = "CMSG_CREATURE_QUERY"; break;
            case 0x061: r = "SMSG_CREATURE_QUERY_RESPONSE"; break;
            case 0x062: r = "CMSG_WHO"; break;
            case 0x063: r = "SMSG_WHO"; break;
            case 0x064: r = "CMSG_WHOIS"; break;
            case 0x065: r = "SMSG_WHOIS"; break;
            case 0x066: r = "CMSG_FRIEND_LIST"; break;
            case 0x067: r = "SMSG_FRIEND_LIST"; break;
            case 0x068: r = "SMSG_FRIEND_STATUS"; break;
            case 0x069: r = "CMSG_ADD_FRIEND"; break;
            case 0x06a: r = "CMSG_DEL_FRIEND"; break;
            case 0x06b: r = "SMSG_IGNORE_LIST"; break;
            case 0x06c: r = "CMSG_ADD_IGNORE"; break;
            case 0x06d: r = "CMSG_DEL_IGNORE"; break;
            case 0x06e: r = "CMSG_GROUP_INVITE"; break;
            case 0x06f: r = "SMSG_GROUP_INVITE"; break;

            case 0x070: r = "CMSG_GROUP_CANCEL"; break;
            case 0x071: r = "SMSG_GROUP_CANCEL"; break;
            case 0x072: r = "CMSG_GROUP_ACCEPT"; break;
            case 0x073: r = "CMSG_GROUP_DECLINE"; break;
            case 0x074: r = "SMSG_GROUP_DECLINE"; break;
            case 0x075: r = "CMSG_GROUP_UNINVITE"; break;
            case 0x076: r = "CMSG_GROUP_UNINVITE_GUID"; break;
            case 0x077: r = "SMSG_GROUP_UNINVITE"; break;
            case 0x078: r = "CMSG_GROUP_SET_LEADER"; break;
            case 0x079: r = "SMSG_GROUP_SET_LEADER"; break;
            case 0x07a: r = "CMSG_LOOT_METHOD"; break;
            case 0x07b: r = "CMSG_GROUP_DISBAND"; break;
            case 0x07c: r = "SMSG_GROUP_DESTROYED"; break;
            case 0x07d: r = "SMSG_GROUP_LIST"; break;
            case 0x07e: r = "SMSG_PARTY_MEMBER_STATS"; break;
            case 0x07f: r = "SMSG_PARTY_COMMAND_RESULT"; break;

            case 0x080: r = "MSG_UPDATE_GROUP_MEMBERS"; break;
            case 0x081: r = "CMSG_GUILD_CREATE"; break;
            case 0x082: r = "CMSG_GUILD_INVITE"; break;
            case 0x083: r = "SMSG_GUILD_INVITE"; break;
            case 0x084: r = "CMSG_GUILD_ACCEPT"; break;
            case 0x085: r = "CMSG_GUILD_DECLINE"; break;
            case 0x086: r = "SMSG_GUILD_DECLINE"; break;
            case 0x087: r = "CMSG_GUILD_INFO"; break;
            case 0x088: r = "SMSG_GUILD_INFO"; break;
            case 0x089: r = "CMSG_GUILD_ROSTER"; break;
            case 0x08a: r = "SMSG_GUILD_ROSTER"; break;
            case 0x08b: r = "CMSG_GUILD_PROMOTE"; break;
            case 0x08c: r = "CMSG_GUILD_DEMOTE"; break;
            case 0x08d: r = "CMSG_GUILD_LEAVE"; break;
            case 0x08e: r = "CMSG_GUILD_REMOVE"; break;
            case 0x08f: r = "CMSG_GUILD_DISBAND"; break;

            case 0x090: r = "CMSG_GUILD_LEADER 	"; break;
            case 0x091: r = "CMSG_GUILD_MOTD 	"; break;
            case 0x092: r = "SMSG_GUILD_EVENT 	"; break;
            case 0x093: r = "SMSG_GUILD_COMMAND_RESULT 	"; break;
            case 0x094: r = "MSG_UPDATE_GUILD 	"; break;
            case 0x095: r = "CMSG_MESSAGECHAT 	"; break;
            case 0x096: r = "SMSG_MESSAGECHAT 	"; break;
            case 0x097: r = "CMSG_JOIN_CHANNEL 	"; break;
            case 0x098: r = "CMSG_LEAVE_CHANNEL 	"; break;
            case 0x099: r = "SMSG_CHANNEL_NOTIFY 	"; break;
            case 0x09A: r = "CMSG_CHANNEL_LIST 	"; break;
            case 0x09B: r = "SMSG_CHANNEL_LIST 	"; break;
            case 0x09C: r = "CMSG_CHANNEL_PASSWORD 	"; break;
            case 0x09D: r = "CMSG_CHANNEL_SET_OWNER 	"; break;
            case 0x09E: r = "CMSG_CHANNEL_OWNER 	"; break;
            case 0x09F: r = "CMSG_CHANNEL_MODERATOR 	"; break;
            case 0x0A0: r = "CMSG_CHANNEL_UNMODERATOR 	"; break;
            case 0x0A1: r = "CMSG_CHANNEL_MUTE 	"; break;
            case 0x0A2: r = "CMSG_CHANNEL_UNMUTE 	"; break;
            case 0x0A3: r = "CMSG_CHANNEL_INVITE 	"; break;
            case 0x0A4: r = "CMSG_CHANNEL_KICK 	"; break;
            case 0x0A5: r = "CMSG_CHANNEL_BAN 	"; break;
            case 0x0A6: r = "CMSG_CHANNEL_UNBAN 	"; break;
            case 0x0A7: r = "CMSG_CHANNEL_ANNOUNCEMENTS 	"; break;
            case 0x0A8: r = "CMSG_CHANNEL_MODERATE 	"; break;
            case 0x0A9: r = "SMSG_UPDATE_OBJECT 	"; break;
            case 0x0AA: r = "SMSG_DESTROY_OBJECT 	"; break;
            case 0x0AB: r = "CMSG_USE_ITEM 	"; break;
            case 0x0AC: r = "CMSG_OPEN_ITEM 	"; break;
            case 0x0AD: r = "CMSG_READ_ITEM 	"; break;
            case 0x0AE: r = "SMSG_READ_ITEM_OK 	"; break;
            case 0x0AF: r = "SMSG_READ_ITEM_FAILED 	"; break;
            case 0x0B0: r = "SMSG_ITEM_COOLDOWN 	"; break;
            case 0x0B1: r = "CMSG_GAMEOBJ_USE 	"; break;
            case 0x0B2: r = "CMSG_GAMEOBJ_CHAIR_USE_OBSOLETE 	"; break;
            case 0x0B3: r = "SMSG_GAMEOBJECT_CUSTOM_ANIM 	"; break;
            case 0x0B4: r = "CMSG_AREATRIGGER 	"; break;
            case 0x0B5: r = "MSG_MOVE_START_FORWARD 	"; break;
            case 0x0B6: r = "MSG_MOVE_START_BACKWARD 	"; break;
            case 0x0B7: r = "MSG_MOVE_STOP 	"; break;
            case 0x0B8: r = "MSG_MOVE_START_STRAFE_LEFT 	"; break;
            case 0x0B9: r = "MSG_MOVE_START_STRAFE_RIGHT 	"; break;
            case 0x0BA: r = "MSG_MOVE_STOP_STRAFE 	"; break;
            case 0x0BB: r = "MSG_MOVE_JUMP 	"; break;
            case 0x0BC: r = "MSG_MOVE_START_TURN_LEFT 	"; break;
            case 0x0BD: r = "MSG_MOVE_START_TURN_RIGHT 	"; break;
            case 0x0BE: r = "MSG_MOVE_STOP_TURN 	"; break;
            case 0x0BF: r = "MSG_MOVE_START_PITCH_UP 	"; break;
            case 0x0C0: r = "MSG_MOVE_START_PITCH_DOWN 	"; break;
            case 0x0C1: r = "MSG_MOVE_STOP_PITCH 	"; break;
            case 0x0C2: r = "MSG_MOVE_SET_RUN_MODE 	"; break;
            case 0x0C3: r = "MSG_MOVE_SET_WALK_MODE 	"; break;
            case 0x0C4: r = "MSG_MOVE_TOGGLE_LOGGING 	"; break;
            case 0x0C5: r = "MSG_MOVE_TELEPORT 	"; break;
            case 0x0C6: r = "MSG_MOVE_TELEPORT_CHEAT 	"; break;
            case 0x0C7: r = "MSG_MOVE_TELEPORT_ACK 	"; break;
            case 0x0C8: r = "MSG_MOVE_TOGGLE_FALL_LOGGING 	"; break;
            case 0x0C9: r = "MSG_MOVE_FALL_LAND 	"; break;
            case 0x0CA: r = "MSG_MOVE_START_SWIM 	"; break;
            case 0x0CB: r = "MSG_MOVE_STOP_SWIM 	"; break;
            case 0x0CC: r = "MSG_MOVE_SET_RUN_SPEED_CHEAT 	"; break;
            case 0x0CD: r = "MSG_MOVE_SET_RUN_SPEED 	"; break;
            case 0x0CE: r = "MSG_MOVE_SET_RUN_BACK_SPEED_CHEAT 	"; break;
            case 0x0CF: r = "MSG_MOVE_SET_RUN_BACK_SPEED 	"; break;
            case 0x0D0: r = "MSG_MOVE_SET_WALK_SPEED_CHEAT 	"; break;
            case 0x0D1: r = "MSG_MOVE_SET_WALK_SPEED 	"; break;
            case 0x0D2: r = "MSG_MOVE_SET_SWIM_SPEED_CHEAT 	"; break;
            case 0x0D3: r = "MSG_MOVE_SET_SWIM_SPEED 	"; break;
            case 0x0D4: r = "MSG_MOVE_SET_SWIM_BACK_SPEED_CHEAT 	"; break;
            case 0x0D5: r = "MSG_MOVE_SET_SWIM_BACK_SPEED 	"; break;
            case 0x0D6: r = "MSG_MOVE_SET_ALL_SPEED_CHEAT 	"; break;
            case 0x0D7: r = "MSG_MOVE_SET_TURN_RATE_CHEAT 	"; break;
            case 0x0D8: r = "MSG_MOVE_SET_TURN_RATE 	"; break;
            case 0x0D9: r = "MSG_MOVE_TOGGLE_COLLISION_CHEAT 	"; break;
            case 0x0DA: r = "MSG_MOVE_SET_FACING 	"; break;
            case 0x0DB: r = "MSG_MOVE_SET_PITCH 	"; break;
            case 0x0DC: r = "MSG_MOVE_WORLDPORT_ACK 	"; break;
            case 0x0DD: r = "SMSG_MONSTER_MOVE 	"; break;
            case 0x0DE: r = "SMSG_MOVE_WATER_WALK 	"; break;
            case 0x0DF: r = "SMSG_MOVE_LAND_WALK 	"; break;
            case 0x0E0: r = "MSG_MOVE_SET_RAW_POSITION_ACK 	"; break;
            case 0x0E1: r = "CMSG_MOVE_SET_RAW_POSITION 	"; break;
            case 0x0E2: r = "SMSG_FORCE_RUN_SPEED_CHANGE 	"; break;
            case 0x0E3: r = "CMSG_FORCE_RUN_SPEED_CHANGE_ACK 	"; break;
            case 0x0E4: r = "SMSG_FORCE_RUN_BACK_SPEED_CHANGE 	"; break;
            case 0x0E5: r = "CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK 	"; break;
            case 0x0E6: r = "SMSG_FORCE_SWIM_SPEED_CHANGE 	"; break;
            case 0x0E7: r = "CMSG_FORCE_SWIM_SPEED_CHANGE_ACK 	"; break;
            case 0x0E8: r = "SMSG_FORCE_MOVE_ROOT 	"; break;
            case 0x0E9: r = "CMSG_FORCE_MOVE_ROOT_ACK 	"; break;
            case 0x0EA: r = "SMSG_FORCE_MOVE_UNROOT 	"; break;
            case 0x0EB: r = "CMSG_FORCE_MOVE_UNROOT_ACK 	"; break;
            case 0x0EC: r = "MSG_MOVE_ROOT 	"; break;
            case 0x0ED: r = "MSG_MOVE_UNROOT 	"; break;
            case 0x0EE: r = "MSG_MOVE_HEARTBEAT 	"; break;
            case 0x0EF: r = "SMSG_MOVE_KNOCK_BACK 	"; break;
            case 0x0F0: r = "CMSG_MOVE_KNOCK_BACK_ACK 	"; break;
            case 0x0F1: r = "MSG_MOVE_KNOCK_BACK 	"; break;
            case 0x0F2: r = "SMSG_MOVE_FEATHER_FALL 	"; break;
            case 0x0F3: r = "SMSG_MOVE_NORMAL_FALL 	"; break;
            case 0x0F4: r = "SMSG_MOVE_SET_HOVER 	"; break;
            case 0x0F5: r = "SMSG_MOVE_UNSET_HOVER 	"; break;
            case 0x0F6: r = "CMSG_MOVE_HOVER_ACK 	"; break;
            case 0x0F7: r = "MSG_MOVE_HOVER 	"; break;
            case 0x0F8: r = "CMSG_TRIGGER_CINEMATIC_CHEAT 	"; break;
            case 0x0F9: r = "CMSG_OPENING_CINEMATIC 	"; break;
            case 0x0FA: r = "SMSG_TRIGGER_CINEMATIC 	"; break;
            case 0x0FB: r = "CMSG_NEXT_CINEMATIC_CAMERA 	"; break;
            case 0x0FC: r = "CMSG_COMPLETE_CINEMATIC 	"; break;
            case 0x0FD: r = "SMSG_TUTORIAL_FLAGS 	"; break;
            case 0x0FE: r = "CMSG_TUTORIAL_FLAG 	"; break;
            case 0x0FF: r = "CMSG_TUTORIAL_CLEAR 	"; break;
            case 0x100: r = "CMSG_TUTORIAL_RESET 	"; break;
            case 0x101: r = "CMSG_STANDSTATECHANGE 	"; break;
            case 0x102: r = "CMSG_EMOTE 	"; break;
            case 0x103: r = "SMSG_EMOTE 	"; break;
            case 0x104: r = "CMSG_TEXT_EMOTE 	"; break;
            case 0x105: r = "SMSG_TEXT_EMOTE 	"; break;
            case 0x106: r = "CMSG_AUTOEQUIP_GROUND_ITEM 	"; break;
            case 0x107: r = "CMSG_AUTOSTORE_GROUND_ITEM 	"; break;
            case 0x108: r = "CMSG_AUTOSTORE_LOOT_ITEM 	"; break;
            case 0x109: r = "CMSG_STORE_LOOT_IN_SLOT 	"; break;
            case 0x10A: r = "CMSG_AUTOEQUIP_ITEM 	"; break;
            case 0x10B: r = "CMSG_AUTOSTORE_BAG_ITEM 	"; break;
            case 0x10C: r = "CMSG_SWAP_ITEM 	"; break;
            case 0x10D: r = "CMSG_SWAP_INV_ITEM 	"; break;
            case 0x10E: r = "CMSG_SPLIT_ITEM 	"; break;
            case 0x10F: r = "CMSG_AUTOEQUIP_ITEM_SLOT 	"; break;
            case 0x110: r = "CMSG_DROP_ITEM 	"; break;
            case 0x111: r = "CMSG_DESTROYITEM 	"; break;
            case 0x112: r = "SMSG_INVENTORY_CHANGE_FAILURE 	"; break;
            case 0x113: r = "SMSG_OPEN_CONTAINER 	"; break;
            case 0x114: r = "CMSG_INSPECT 	"; break;
            case 0x115: r = "SMSG_INSPECT 	"; break;
            case 0x116: r = "CMSG_INITIATE_TRADE 	"; break;
            case 0x117: r = "CMSG_BEGIN_TRADE 	"; break;
            case 0x118: r = "CMSG_BUSY_TRADE 	"; break;
            case 0x119: r = "CMSG_IGNORE_TRADE 	"; break;
            case 0x11A: r = "CMSG_ACCEPT_TRADE 	"; break;
            case 0x11B: r = "CMSG_UNACCEPT_TRADE 	"; break;
            case 0x11C: r = "CMSG_CANCEL_TRADE 	"; break;
            case 0x11D: r = "CMSG_SET_TRADE_ITEM 	"; break;
            case 0x11E: r = "CMSG_CLEAR_TRADE_ITEM 	"; break;
            case 0x11F: r = "CMSG_SET_TRADE_GOLD 	"; break;
            case 0x120: r = "SMSG_TRADE_STATUS 	"; break;
            case 0x121: r = "SMSG_TRADE_STATUS_EXTENDED 	"; break;
            case 0x122: r = "SMSG_INITIALIZE_FACTIONS 	"; break;
            case 0x123: r = "SMSG_SET_FACTION_VISIBLE 	"; break;
            case 0x124: r = "SMSG_SET_FACTION_STANDING 	"; break;
            case 0x125: r = "CMSG_SET_FACTION_ATWAR 	"; break;
            case 0x126: r = "CMSG_SET_FACTION_CHEAT 	"; break;
            case 0x127: r = "SMSG_SET_PROFICIENCY 	"; break;
            case 0x128: r = "CMSG_SET_ACTION_BUTTON 	"; break;
            case 0x129: r = "SMSG_ACTION_BUTTONS 	"; break;
            case 0x12A: r = "SMSG_INITIAL_SPELLS 	"; break;
            case 0x12B: r = "SMSG_LEARNED_SPELL 	"; break;
            case 0x12C: r = "SMSG_SUPERCEDED_SPELL 	"; break;
            case 0x12D: r = "CMSG_NEW_SPELL_SLOT 	"; break;
            case 0x12E: r = "CMSG_CAST_SPELL 	"; break;
            case 0x12F: r = "CMSG_CANCEL_CAST 	"; break;
            case 0x130: r = "SMSG_CAST_RESULT 	"; break;
            case 0x131: r = "SMSG_SPELL_START 	"; break;
            case 0x132: r = "SMSG_SPELL_GO 	"; break;
            case 0x133: r = "SMSG_SPELL_FAILURE 	"; break;
            case 0x134: r = "SMSG_SPELL_COOLDOWN 	"; break;
            case 0x135: r = "SMSG_COOLDOWN_EVENT 	"; break;
            case 0x136: r = "CMSG_CANCEL_AURA 	"; break;
            case 0x137: r = "SMSG_UPDATE_AURA_DURATION 	"; break;
            case 0x138: r = "SMSG_PET_CAST_FAILED 	"; break;
            case 0x139: r = "MSG_CHANNEL_START 	"; break;
            case 0x13A: r = "MSG_CHANNEL_UPDATE 	"; break;
            case 0x13B: r = "CMSG_CANCEL_CHANNELLING 	"; break;
            case 0x13C: r = "SMSG_AI_REACTION 	"; break;
            case 0x13D: r = "CMSG_SET_SELECTION 	"; break;
            case 0x13E: r = "CMSG_SET_TARGET_OBSOLETE 	"; break;
            case 0x13F: r = "CMSG_UNUSED 	"; break;
            case 0x140: r = "CMSG_UNUSED2 	"; break;
            case 0x141: r = "CMSG_ATTACKSWING 	"; break;
            case 0x142: r = "CMSG_ATTACKSTOP 	"; break;
            case 0x143: r = "SMSG_ATTACKSTART 	"; break;
            case 0x144: r = "SMSG_ATTACKSTOP 	"; break;
            case 0x145: r = "SMSG_ATTACKSWING_NOTINRANGE 	"; break;
            case 0x146: r = "SMSG_ATTACKSWING_BADFACING 	"; break;
            case 0x147: r = "SMSG_ATTACKSWING_NOTSTANDING 	"; break;
            case 0x148: r = "SMSG_ATTACKSWING_DEADTARGET 	"; break;
            case 0x149: r = "SMSG_ATTACKSWING_CANT_ATTACK 	"; break;
            case 0x14A: r = "SMSG_ATTACKERSTATEUPDATE 	"; break;
            case 0x14B: r = "SMSG_VICTIMSTATEUPDATE_OBSOLETE 	"; break;
            case 0x14C: r = "SMSG_DAMAGE_DONE_OBSOLETE 	"; break;
            case 0x14D: r = "SMSG_DAMAGE_TAKEN_OBSOLETE 	"; break;
            case 0x14E: r = "SMSG_CANCEL_COMBAT 	"; break;
            case 0x14F: r = "SMSG_PLAYER_COMBAT_XP_GAIN_OBSOLETE 	"; break;
            case 0x150: r = "SMSG_SPELLHEALLOG 	"; break;
            case 0x151: r = "SMSG_SPELLENERGIZELOG 	"; break;
            case 0x152: r = "CMSG_SHEATHE_OBSOLETE 	"; break;
            case 0x153: r = "CMSG_SAVE_PLAYER 	"; break;
            case 0x154: r = "CMSG_SETDEATHBINDPOINT 	"; break;
            case 0x155: r = "SMSG_BINDPOINTUPDATE 	"; break;
            case 0x156: r = "CMSG_GETDEATHBINDZONE 	"; break;
            case 0x157: r = "SMSG_BINDZONEREPLY 	"; break;
            case 0x158: r = "SMSG_PLAYERBOUND 	"; break;
            case 0x159: r = "SMSG_CLIENT_CONTROL_UPDATE 	"; break;
            case 0x15A: r = "CMSG_REPOP_REQUEST 	"; break;
            case 0x15B: r = "SMSG_RESURRECT_REQUEST 	"; break;
            case 0x15C: r = "CMSG_RESURRECT_RESPONSE 	"; break;
            case 0x15D: r = "CMSG_LOOT 	"; break;
            case 0x15E: r = "CMSG_LOOT_MONEY 	"; break;
            case 0x15F: r = "CMSG_LOOT_RELEASE 	"; break;
            case 0x160: r = "SMSG_LOOT_RESPONSE 	"; break;
            case 0x161: r = "SMSG_LOOT_RELEASE_RESPONSE 	"; break;
            case 0x162: r = "SMSG_LOOT_REMOVED 	"; break;
            case 0x163: r = "SMSG_LOOT_MONEY_NOTIFY 	"; break;
            case 0x164: r = "SMSG_LOOT_ITEM_NOTIFY 	"; break;
            case 0x165: r = "SMSG_LOOT_CLEAR_MONEY 	"; break;
            case 0x166: r = "SMSG_ITEM_PUSH_RESULT 	"; break;
            case 0x167: r = "SMSG_DUEL_REQUESTED 	"; break;
            case 0x168: r = "SMSG_DUEL_OUTOFBOUNDS 	"; break;
            case 0x169: r = "SMSG_DUEL_INBOUNDS 	"; break;
            case 0x16A: r = "SMSG_DUEL_COMPLETE 	"; break;
            case 0x16B: r = "SMSG_DUEL_WINNER 	"; break;
            case 0x16C: r = "CMSG_DUEL_ACCEPTED 	"; break;
            case 0x16D: r = "CMSG_DUEL_CANCELLED 	"; break;
            case 0x16E: r = "SMSG_MOUNTRESULT 	"; break;
            case 0x16F: r = "SMSG_DISMOUNTRESULT 	"; break;
            case 0x170: r = "SMSG_PUREMOUNT_CANCELLED_OBSOLETE 	"; break;
            case 0x171: r = "CMSG_MOUNTSPECIAL_ANIM 	"; break;
            case 0x172: r = "SMSG_MOUNTSPECIAL_ANIM 	"; break;
            case 0x173: r = "SMSG_PET_TAME_FAILURE 	"; break;
            case 0x174: r = "CMSG_PET_SET_ACTION 	"; break;
            case 0x175: r = "CMSG_PET_ACTION 	"; break;
            case 0x176: r = "CMSG_PET_ABANDON 	"; break;
            case 0x177: r = "CMSG_PET_RENAME 	"; break;
            case 0x178: r = "SMSG_PET_NAME_INVALID 	"; break;
            case 0x179: r = "SMSG_PET_SPELLS 	"; break;
            case 0x17A: r = "SMSG_PET_MODE 	"; break;
            case 0x17B: r = "CMSG_GOSSIP_HELLO 	"; break;
            case 0x17C: r = "CMSG_GOSSIP_SELECT_OPTION 	"; break;
            case 0x17D: r = "SMSG_GOSSIP_MESSAGE 	"; break;
            case 0x17E: r = "SMSG_GOSSIP_COMPLETE 	"; break;
            case 0x17F: r = "CMSG_NPC_TEXT_QUERY 	"; break;
            case 0x180: r = "SMSG_NPC_TEXT_UPDATE 	"; break;
            case 0x181: r = "SMSG_NPC_WONT_TALK 	"; break;
            case 0x182: r = "CMSG_QUESTGIVER_STATUS_QUERY 	"; break;
            case 0x183: r = "SMSG_QUESTGIVER_STATUS 	"; break;
            case 0x184: r = "CMSG_QUESTGIVER_HELLO 	"; break;
            case 0x185: r = "SMSG_QUESTGIVER_QUEST_LIST 	"; break;
            case 0x186: r = "CMSG_QUESTGIVER_QUERY_QUEST 	"; break;
            case 0x187: r = "CMSG_QUESTGIVER_QUEST_AUTOLAUNCH 	"; break;
            case 0x188: r = "SMSG_QUESTGIVER_QUEST_DETAILS 	"; break;
            case 0x189: r = "CMSG_QUESTGIVER_ACCEPT_QUEST 	"; break;
            case 0x18A: r = "CMSG_QUESTGIVER_COMPLETE_QUEST 	"; break;
            case 0x18B: r = "SMSG_QUESTGIVER_REQUEST_ITEMS 	"; break;
            case 0x18C: r = "CMSG_QUESTGIVER_REQUEST_REWARD 	"; break;
            case 0x18D: r = "SMSG_QUESTGIVER_OFFER_REWARD 	"; break;
            case 0x18E: r = "CMSG_QUESTGIVER_CHOOSE_REWARD 	"; break;
            case 0x18F: r = "SMSG_QUESTGIVER_QUEST_INVALID 	"; break;
            case 0x190: r = "CMSG_QUESTGIVER_CANCEL 	"; break;
            case 0x191: r = "SMSG_QUESTGIVER_QUEST_COMPLETE 	"; break;
            case 0x192: r = "SMSG_QUESTGIVER_QUEST_FAILED 	"; break;
            case 0x193: r = "CMSG_QUESTLOG_SWAP_QUEST 	"; break;
            case 0x194: r = "CMSG_QUESTLOG_REMOVE_QUEST 	"; break;
            case 0x195: r = "SMSG_QUESTLOG_FULL 	"; break;
            case 0x196: r = "SMSG_QUESTUPDATE_FAILED 	"; break;
            case 0x197: r = "SMSG_QUESTUPDATE_FAILEDTIMER 	"; break;
            case 0x198: r = "SMSG_QUESTUPDATE_COMPLETE 	"; break;
            case 0x199: r = "SMSG_QUESTUPDATE_ADD_KILL 	"; break;
            case 0x19A: r = "SMSG_QUESTUPDATE_ADD_ITEM 	"; break;
            case 0x19B: r = "CMSG_QUEST_CONFIRM_ACCEPT 	"; break;
            case 0x19C: r = "SMSG_QUEST_CONFIRM_ACCEPT 	"; break;
            case 0x19D: r = "CMSG_PUSHQUESTTOPARTY 	"; break;
            case 0x19E: r = "CMSG_LIST_INVENTORY 	"; break;
            case 0x19F: r = "SMSG_LIST_INVENTORY 	"; break;
            case 0x1A0: r = "CMSG_SELL_ITEM 	"; break;
            case 0x1A1: r = "SMSG_SELL_ITEM 	"; break;
            case 0x1A2: r = "CMSG_BUY_ITEM 	"; break;
            case 0x1A3: r = "CMSG_BUY_ITEM_IN_SLOT 	"; break;
            case 0x1A4: r = "SMSG_BUY_ITEM 	"; break;
            case 0x1A5: r = "SMSG_BUY_FAILED 	"; break;
            case 0x1A6: r = "CMSG_TAXICLEARALLNODES 	"; break;
            case 0x1A7: r = "CMSG_TAXIENABLEALLNODES 	"; break;
            case 0x1A8: r = "CMSG_TAXISHOWNODES 	"; break;
            case 0x1A9: r = "SMSG_SHOWTAXINODES 	"; break;
            case 0x1AA: r = "CMSG_TAXINODE_STATUS_QUERY 	"; break;
            case 0x1AB: r = "SMSG_TAXINODE_STATUS 	"; break;
            case 0x1AC: r = "CMSG_TAXIQUERYAVAILABLENODES 	"; break;
            case 0x1AD: r = "CMSG_ACTIVATETAXI 	"; break;
            case 0x1AE: r = "SMSG_ACTIVATETAXIREPLY 	"; break;
            case 0x1AF: r = "SMSG_NEW_TAXI_PATH 	"; break;
            case 0x1B0: r = "CMSG_TRAINER_LIST 	"; break;
            case 0x1B1: r = "SMSG_TRAINER_LIST 	"; break;
            case 0x1B2: r = "CMSG_TRAINER_BUY_SPELL 	"; break;
            case 0x1B3: r = "SMSG_TRAINER_BUY_SUCCEEDED 	"; break;
            case 0x1B4: r = "SMSG_TRAINER_BUY_FAILED 	"; break;
            case 0x1B5: r = "CMSG_BINDER_ACTIVATE 	"; break;
            case 0x1B6: r = "SMSG_PLAYERBINDERROR 	"; break;
            case 0x1B7: r = "CMSG_BANKER_ACTIVATE 	"; break;
            case 0x1B8: r = "SMSG_SHOW_BANK 	"; break;
            case 0x1B9: r = "CMSG_BUY_BANK_SLOT 	"; break;
            case 0x1BA: r = "SMSG_BUY_BANK_SLOT_RESULT 	"; break;
            case 0x1BB: r = "CMSG_PETITION_SHOWLIST 	"; break;
            case 0x1BC: r = "SMSG_PETITION_SHOWLIST 	"; break;
            case 0x1BD: r = "CMSG_PETITION_BUY 	"; break;
            case 0x1BE: r = "CMSG_PETITION_SHOW_SIGNATURES 	"; break;
            case 0x1BF: r = "SMSG_PETITION_SHOW_SIGNATURES 	"; break;
            case 0x1C0: r = "CMSG_PETITION_SIGN 	"; break;
            case 0x1C1: r = "SMSG_PETITION_SIGN_RESULTS 	"; break;
            case 0x1C2: r = "MSG_PETITION_DECLINE 	"; break;
            case 0x1C3: r = "CMSG_OFFER_PETITION 	"; break;
            case 0x1C4: r = "CMSG_TURN_IN_PETITION 	"; break;
            case 0x1C5: r = "SMSG_TURN_IN_PETITION_RESULTS 	"; break;
            case 0x1C6: r = "CMSG_PETITION_QUERY 	"; break;
            case 0x1C7: r = "SMSG_PETITION_QUERY_RESPONSE 	"; break;
            case 0x1C8: r = "SMSG_FISH_NOT_HOOKED 	"; break;
            case 0x1C9: r = "SMSG_FISH_ESCAPED 	"; break;
            case 0x1CA: r = "CMSG_BUG 	"; break;
            case 0x1CB: r = "SMSG_NOTIFICATION 	"; break;
            case 0x1CC: r = "CMSG_PLAYED_TIME 	"; break;
            case 0x1CD: r = "SMSG_PLAYED_TIME 	"; break;
            case 0x1CE: r = "CMSG_QUERY_TIME 	"; break;
            case 0x1CF: r = "SMSG_QUERY_TIME_RESPONSE 	"; break;
            case 0x1D0: r = "SMSG_LOG_XPGAIN 	"; break;
            case 0x1D1: r = "SMSG_AURACASTLOG 	"; break;
            case 0x1D2: r = "CMSG_RECLAIM_CORPSE 	"; break;
            case 0x1D3: r = "CMSG_WRAP_ITEM 	"; break;
            case 0x1D4: r = "SMSG_LEVELUP_INFO 	"; break;
            case 0x1D5: r = "MSG_MINIMAP_PING 	"; break;
            case 0x1D6: r = "SMSG_RESISTLOG 	"; break;
            case 0x1D7: r = "SMSG_ENCHANTMENTLOG 	"; break;
            case 0x1D8: r = "CMSG_SET_SKILL_CHEAT 	"; break;
            case 0x1D9: r = "SMSG_START_MIRROR_TIMER 	"; break;
            case 0x1DA: r = "SMSG_PAUSE_MIRROR_TIMER 	"; break;
            case 0x1DB: r = "SMSG_STOP_MIRROR_TIMER 	"; break;
            case 0x1DC: r = "CMSG_PING 	"; break;
            case 0x1DD: r = "SMSG_PONG 	"; break;
            case 0x1DE: r = "SMSG_CLEAR_COOLDOWN 	"; break;
            case 0x1DF: r = "SMSG_GAMEOBJECT_PAGETEXT 	"; break;
            case 0x1E0: r = "CMSG_SETSHEATHED 	"; break;
            case 0x1E1: r = "SMSG_COOLDOWN_CHEAT 	"; break;
            case 0x1E2: r = "SMSG_SPELL_DELAYED 	"; break;
            case 0x1E3: r = "CMSG_PLAYER_MACRO_OBSOLETE 	"; break;
            case 0x1E4: r = "SMSG_PLAYER_MACRO_OBSOLETE 	"; break;
            case 0x1E5: r = "CMSG_GHOST 	"; break;
            case 0x1E6: r = "CMSG_GM_INVIS 	"; break;
            case 0x1E7: r = "SMSG_INVALID_PROMOTION_CODE 	"; break;
            case 0x1E8: r = "MSG_GM_BIND_OTHER 	"; break;
            case 0x1E9: r = "MSG_GM_SUMMON 	"; break;
            case 0x1EA: r = "SMSG_ITEM_TIME_UPDATE 	"; break;
            case 0x1EB: r = "SMSG_ITEM_ENCHANT_TIME_UPDATE 	"; break;
            case 0x1EC: r = "SMSG_AUTH_CHALLENGE 	"; break;
            case 0x1ED: r = "CMSG_AUTH_SESSION 	"; break;
            case 0x1EE: r = "SMSG_AUTH_RESPONSE 	"; break;
            case 0x1EF: r = "MSG_GM_SHOWLABEL 	"; break;
            case 0x1F0: r = "CMSG_PET_CAST_SPELL 	"; break;
            case 0x1F1: r = "MSG_SAVE_GUILD_EMBLEM 	"; break;
            case 0x1F2: r = "MSG_TABARDVENDOR_ACTIVATE 	"; break;
            case 0x1F3: r = "SMSG_PLAY_SPELL_VISUAL 	"; break;
            case 0x1F4: r = "CMSG_ZONEUPDATE 	"; break;
            case 0x1F5: r = "SMSG_PARTYKILLLOG 	"; break;
            case 0x1F6: r = "SMSG_COMPRESSED_UPDATE_OBJECT 	"; break;
            case 0x1F7: r = "SMSG_PLAY_SPELL_IMPACT 	"; break;
            case 0x1F8: r = "SMSG_EXPLORATION_EXPERIENCE 	"; break;
            case 0x1F9: r = "CMSG_GM_SET_SECURITY_GROUP 	"; break;
            case 0x1FA: r = "CMSG_GM_NUKE 	"; break;
            case 0x1FB: r = "MSG_RANDOM_ROLL 	"; break;
            case 0x1FC: r = "SMSG_ENVIRONMENTALDAMAGELOG 	"; break;
            case 0x1FD: r = "CMSG_RWHOIS 	"; break;
            case 0x1FE: r = "SMSG_RWHOIS 	"; break;
            case 0x1FF: r = "MSG_LOOKING_FOR_GROUP 	"; break;
            case 0x200: r = "CMSG_SET_LOOKING_FOR_GROUP 	"; break;
            case 0x201: r = "CMSG_UNLEARN_SPELL 	"; break;
            case 0x202: r = "CMSG_UNLEARN_SKILL 	"; break;
            case 0x203: r = "SMSG_REMOVED_SPELL 	"; break;
            case 0x204: r = "CMSG_DECHARGE 	"; break;
            case 0x205: r = "CMSG_GMTICKET_CREATE 	"; break;
            case 0x206: r = "SMSG_GMTICKET_CREATE 	"; break;
            case 0x207: r = "CMSG_GMTICKET_UPDATETEXT 	"; break;
            case 0x208: r = "SMSG_GMTICKET_UPDATETEXT 	"; break;
            case 0x209: r = "SMSG_ACCOUNT_DATA_TIMES 	"; break;
            case 0x20A: r = "CMSG_REQUEST_ACCOUNT_DATA 	"; break;
            case 0x20B: r = "CMSG_UPDATE_ACCOUNT_DATA 	"; break;
            case 0x20C: r = "SMSG_UPDATE_ACCOUNT_DATA 	"; break;
            case 0x20D: r = "SMSG_CLEAR_FAR_SIGHT_IMMEDIATE 	"; break;
            case 0x20E: r = "SMSG_POWERGAINLOG_OBSOLETE 	"; break;
            case 0x20F: r = "CMSG_GM_TEACH 	"; break;
            case 0x210: r = "CMSG_GM_CREATE_ITEM_TARGET 	"; break;
            case 0x211: r = "CMSG_GMTICKET_GETTICKET 	"; break;
            case 0x212: r = "SMSG_GMTICKET_GETTICKET 	"; break;
            case 0x213: r = "CMSG_UNLEARN_TALENTS 	"; break;
            case 0x214: r = "SMSG_GAMEOBJECT_SPAWN_ANIM 	"; break;
            case 0x215: r = "SMSG_GAMEOBJECT_DESPAWN_ANIM 	"; break;
            case 0x216: r = "MSG_CORPSE_QUERY 	"; break;
            case 0x217: r = "CMSG_GMTICKET_DELETETICKET 	"; break;
            case 0x218: r = "SMSG_GMTICKET_DELETETICKET 	"; break;
            case 0x219: r = "SMSG_CHAT_WRONG_FACTION 	"; break;
            case 0x21A: r = "CMSG_GMTICKET_SYSTEMSTATUS 	"; break;
            case 0x21B: r = "SMSG_GMTICKET_SYSTEMSTATUS 	"; break;
            case 0x21C: r = "CMSG_SPIRIT_HEALER_ACTIVATE 	"; break;
            case 0x21D: r = "CMSG_SET_STAT_CHEAT 	"; break;
            case 0x21E: r = "SMSG_SET_REST_START 	"; break;
            case 0x21F: r = "CMSG_SKILL_BUY_STEP 	"; break;
            case 0x220: r = "CMSG_SKILL_BUY_RANK 	"; break;
            case 0x221: r = "CMSG_XP_CHEAT 	"; break;
            case 0x222: r = "SMSG_SPIRIT_HEALER_CONFIRM 	"; break;
            case 0x223: r = "CMSG_CHARACTER_POINT_CHEAT 	"; break;
            case 0x224: r = "SMSG_GOSSIP_POI 	"; break;
            case 0x225: r = "CMSG_CHAT_IGNORED 	"; break;
            case 0x226: r = "CMSG_GM_VISION 	"; break;
            case 0x227: r = "CMSG_SERVER_COMMAND 	"; break;
            case 0x228: r = "CMSG_GM_SILENCE 	"; break;
            case 0x229: r = "CMSG_GM_REVEALTO 	"; break;
            case 0x22A: r = "CMSG_GM_RESURRECT 	"; break;
            case 0x22B: r = "CMSG_GM_SUMMONMOB 	"; break;
            case 0x22C: r = "CMSG_GM_MOVECORPSE 	"; break;
            case 0x22D: r = "CMSG_GM_FREEZE 	"; break;
            case 0x22E: r = "CMSG_GM_UBERINVIS 	"; break;
            case 0x22F: r = "CMSG_GM_REQUEST_PLAYER_INFO 	"; break;
            case 0x230: r = "SMSG_GM_PLAYER_INFO 	"; break;
            case 0x231: r = "CMSG_GUILD_RANK 	"; break;
            case 0x232: r = "CMSG_GUILD_ADD_RANK 	"; break;
            case 0x233: r = "CMSG_GUILD_DEL_RANK 	"; break;
            case 0x234: r = "CMSG_GUILD_SET_PUBLIC_NOTE 	"; break;
            case 0x235: r = "CMSG_GUILD_SET_OFFICER_NOTE 	"; break;
            case 0x236: r = "SMSG_LOGIN_VERIFY_WORLD 	"; break;
            case 0x237: r = "CMSG_CLEAR_EXPLORATION 	"; break;
            case 0x238: r = "CMSG_SEND_MAIL 	"; break;
            case 0x239: r = "SMSG_SEND_MAIL_RESULT 	"; break;
            case 0x23A: r = "CMSG_GET_MAIL_LIST 	"; break;
            case 0x23B: r = "SMSG_MAIL_LIST_RESULT 	"; break;
            case 0x23C: r = "CMSG_BATTLEFIELD_LIST 	"; break;
            case 0x23D: r = "SMSG_BATTLEFIELD_LIST 	"; break;
            case 0x23E: r = "CMSG_BATTLEFIELD_JOIN 	"; break;
            case 0x23F: r = "SMSG_BATTLEFIELD_WIN 	"; break;
            case 0x240: r = "SMSG_BATTLEFIELD_LOSE 	"; break;
            case 0x241: r = "CMSG_TAXICLEARNODE 	"; break;
            case 0x242: r = "CMSG_TAXIENABLENODE 	"; break;
            case 0x243: r = "CMSG_ITEM_TEXT_QUERY 	"; break;
            case 0x244: r = "SMSG_ITEM_TEXT_QUERY_RESPONSE 	"; break;
            case 0x245: r = "CMSG_MAIL_TAKE_MONEY 	"; break;
            case 0x246: r = "CMSG_MAIL_TAKE_ITEM 	"; break;
            case 0x247: r = "CMSG_MAIL_MARK_AS_READ 	"; break;
            case 0x248: r = "CMSG_MAIL_RETURN_TO_SENDER 	"; break;
            case 0x249: r = "CMSG_MAIL_DELETE 	"; break;
            case 0x24A: r = "CMSG_MAIL_CREATE_TEXT_ITEM 	"; break;
            case 0x24B: r = "SMSG_SPELLLOGMISS 	"; break;
            case 0x24C: r = "SMSG_SPELLLOGEXECUTE 	"; break;
            case 0x24D: r = "SMSG_DEBUGAURAPROC 	"; break;
            case 0x24E: r = "SMSG_PERIODICAURALOG 	"; break;
            case 0x24F: r = "SMSG_SPELLDAMAGESHIELD 	"; break;
            case 0x250: r = "SMSG_SPELLNONMELEEDAMAGELOG 	"; break;
            case 0x251: r = "CMSG_LEARN_TALENT 	"; break;
            case 0x252: r = "SMSG_RESURRECT_FAILED 	"; break;
            case 0x253: r = "CMSG_TOGGLE_PVP 	"; break;
            case 0x254: r = "SMSG_ZONE_UNDER_ATTACK 	"; break;
            case 0x255: r = "MSG_AUCTION_HELLO 	"; break;
            case 0x256: r = "CMSG_AUCTION_SELL_ITEM 	"; break;
            case 0x257: r = "CMSG_AUCTION_REMOVE_ITEM 	"; break;
            case 0x258: r = "CMSG_AUCTION_LIST_ITEMS 	"; break;
            case 0x259: r = "CMSG_AUCTION_LIST_OWNER_ITEMS 	"; break;
            case 0x25A: r = "CMSG_AUCTION_PLACE_BID 	"; break;
            case 0x25B: r = "SMSG_AUCTION_COMMAND_RESULT 	"; break;
            case 0x25C: r = "SMSG_AUCTION_LIST_RESULT 	"; break;
            case 0x25D: r = "SMSG_AUCTION_OWNER_LIST_RESULT 	"; break;
            case 0x25E: r = "SMSG_AUCTION_BIDDER_NOTIFICATION 	"; break;
            case 0x25F: r = "SMSG_AUCTION_OWNER_NOTIFICATION 	"; break;
            case 0x260: r = "SMSG_PROCRESIST 	"; break;
            case 0x261: r = "SMSG_STANDSTATE_CHANGE_FAILURE 	"; break;
            case 0x262: r = "SMSG_DISPEL_FAILED 	"; break;
            case 0x263: r = "SMSG_SPELLORDAMAGE_IMMUNE 	"; break;
            case 0x264: r = "CMSG_AUCTION_LIST_BIDDER_ITEMS 	"; break;
            case 0x265: r = "SMSG_AUCTION_BIDDER_LIST_RESULT 	"; break;
            case 0x266: r = "SMSG_SET_FLAT_SPELL_MODIFIER 	"; break;
            case 0x267: r = "SMSG_SET_PCT_SPELL_MODIFIER 	"; break;
            case 0x268: r = "CMSG_SET_AMMO 	"; break;
            case 0x269: r = "SMSG_CORPSE_RECLAIM_DELAY 	"; break;
            case 0x26A: r = "CMSG_SET_ACTIVE_MOVER 	"; break;
            case 0x26B: r = "CMSG_PET_CANCEL_AURA 	"; break;
            case 0x26C: r = "CMSG_PLAYER_AI_CHEAT 	"; break;
            case 0x26D: r = "CMSG_CANCEL_AUTO_REPEAT_SPELL 	"; break;
            case 0x26E: r = "MSG_GM_ACCOUNT_ONLINE 	"; break;
            case 0x26F: r = "MSG_LIST_STABLED_PETS 	"; break;
            case 0x270: r = "CMSG_STABLE_PET 	"; break;
            case 0x271: r = "CMSG_UNSTABLE_PET 	"; break;
            case 0x272: r = "CMSG_BUY_STABLE_SLOT 	"; break;
            case 0x273: r = "SMSG_STABLE_RESULT 	"; break;
            case 0x274: r = "CMSG_STABLE_REVIVE_PET 	"; break;
            case 0x275: r = "CMSG_STABLE_SWAP_PET 	"; break;
            case 0x276: r = "MSG_QUEST_PUSH_RESULT 	"; break;
            case 0x277: r = "SMSG_PLAY_MUSIC 	"; break;
            case 0x278: r = "SMSG_PLAY_OBJECT_SOUND 	"; break;
            case 0x279: r = "CMSG_REQUEST_PET_INFO 	"; break;
            case 0x27A: r = "CMSG_FAR_SIGHT 	"; break;
            case 0x27B: r = "SMSG_SPELLDISPELLOG 	"; break;
            case 0x27C: r = "SMSG_DAMAGE_CALC_LOG 	"; break;
            case 0x27D: r = "CMSG_ENABLE_DAMAGE_LOG 	"; break;
            case 0x27E: r = "CMSG_GROUP_CHANGE_SUB_GROUP 	"; break;
            case 0x27F: r = "CMSG_REQUEST_PARTY_MEMBER_STATS 	"; break;
            case 0x280: r = "CMSG_GROUP_SWAP_SUB_GROUP 	"; break;
            case 0x281: r = "CMSG_RESET_FACTION_CHEAT 	"; break;
            case 0x282: r = "CMSG_AUTOSTORE_BANK_ITEM 	"; break;
            case 0x283: r = "CMSG_AUTOBANK_ITEM 	"; break;
            case 0x284: r = "MSG_QUERY_NEXT_MAIL_TIME 	"; break;
            case 0x285: r = "SMSG_RECEIVED_MAIL 	"; break;
            case 0x286: r = "SMSG_RAID_GROUP_ONLY 	"; break;
            case 0x287: r = "CMSG_SET_DURABILITY_CHEAT 	"; break;
            case 0x288: r = "CMSG_SET_PVP_RANK_CHEAT 	"; break;
            case 0x289: r = "CMSG_ADD_PVP_MEDAL_CHEAT 	"; break;
            case 0x28A: r = "CMSG_DEL_PVP_MEDAL_CHEAT 	"; break;
            case 0x28B: r = "CMSG_SET_PVP_TITLE 	"; break;
            case 0x28C: r = "SMSG_PVP_CREDIT 	"; break;
            case 0x28D: r = "SMSG_AUCTION_REMOVED_NOTIFICATION 	"; break;
            case 0x28E: r = "CMSG_GROUP_RAID_CONVERT 	"; break;
            case 0x28F: r = "CMSG_GROUP_ASSISTANT_LEADER 	"; break;
            case 0x290: r = "CMSG_BUYBACK_ITEM 	"; break;
            case 0x291: r = "SMSG_SERVER_MESSAGE 	"; break;
            case 0x292: r = "CMSG_MEETINGSTONE_JOIN 	"; break;
            case 0x293: r = "CMSG_MEETINGSTONE_LEAVE 	"; break;
            case 0x294: r = "CMSG_MEETINGSTONE_CHEAT 	"; break;
            case 0x295: r = "SMSG_MEETINGSTONE_SETQUEUE 	"; break;
            case 0x296: r = "CMSG_MEETINGSTONE_INFO 	"; break;
            case 0x297: r = "SMSG_MEETINGSTONE_COMPLETE 	"; break;
            case 0x298: r = "SMSG_MEETINGSTONE_IN_PROGRESS 	"; break;
            case 0x299: r = "SMSG_MEETINGSTONE_MEMBER_ADDED 	"; break;
            case 0x29A: r = "CMSG_GMTICKETSYSTEM_TOGGLE 	"; break;
            case 0x29B: r = "CMSG_CANCEL_GROWTH_AURA 	"; break;
            case 0x29C: r = "SMSG_CANCEL_AUTO_REPEAT 	"; break;
            case 0x29D: r = "SMSG_STANDSTATE_UPDATE 	"; break;
            case 0x29E: r = "SMSG_LOOT_ALL_PASSED 	"; break;
            case 0x29F: r = "SMSG_LOOT_ROLL_WON 	"; break;
            case 0x2A0: r = "CMSG_LOOT_ROLL 	"; break;
            case 0x2A1: r = "SMSG_LOOT_START_ROLL 	"; break;
            case 0x2A2: r = "SMSG_LOOT_ROLL 	"; break;
            case 0x2A3: r = "CMSG_LOOT_MASTER_GIVE 	"; break;
            case 0x2A4: r = "SMSG_LOOT_MASTER_LIST 	"; break;
            case 0x2A5: r = "SMSG_SET_FORCED_REACTIONS 	"; break;
            case 0x2A6: r = "SMSG_SPELL_FAILED_OTHER 	"; break;
            case 0x2A7: r = "SMSG_GAMEOBJECT_RESET_STATE 	"; break;
            case 0x2A8: r = "CMSG_REPAIR_ITEM 	"; break;
            case 0x2A9: r = "SMSG_CHAT_PLAYER_NOT_FOUND 	"; break;
            case 0x2AA: r = "MSG_TALENT_WIPE_CONFIRM 	"; break;
            case 0x2AB: r = "SMSG_SUMMON_REQUEST 	"; break;
            case 0x2AC: r = "CMSG_SUMMON_RESPONSE 	"; break;
            case 0x2AD: r = "MSG_MOVE_TOGGLE_GRAVITY_CHEAT 	"; break;
            case 0x2AE: r = "SMSG_MONSTER_MOVE_TRANSPORT 	"; break;
            case 0x2AF: r = "SMSG_PET_BROKEN 	"; break;
            case 0x2B0: r = "MSG_MOVE_FEATHER_FALL 	"; break;
            case 0x2B1: r = "MSG_MOVE_WATER_WALK 	"; break;
            case 0x2B2: r = "CMSG_SERVER_BROADCAST 	"; break;
            case 0x2B3: r = "CMSG_SELF_RES 	"; break;
            case 0x2B4: r = "SMSG_FEIGN_DEATH_RESISTED 	"; break;
            case 0x2B5: r = "CMSG_RUN_SCRIPT 	"; break;
            case 0x2B6: r = "SMSG_SCRIPT_MESSAGE 	"; break;
            case 0x2B7: r = "SMSG_DUEL_COUNTDOWN 	"; break;
            case 0x2B8: r = "SMSG_AREA_TRIGGER_MESSAGE 	"; break;
            case 0x2B9: r = "CMSG_TOGGLE_HELM 	"; break;
            case 0x2BA: r = "CMSG_TOGGLE_CLOAK 	"; break;
            case 0x2BB: r = "SMSG_MEETINGSTONE_JOINFAILED 	"; break;
            case 0x2BC: r = "SMSG_PLAYER_SKINNED 	"; break;
            case 0x2BD: r = "SMSG_DURABILITY_DAMAGE_DEATH 	"; break;
            case 0x2BE: r = "CMSG_SET_EXPLORATION 	"; break;
            case 0x2BF: r = "CMSG_SET_ACTIONBAR_TOGGLES 	"; break;
            case 0x2C0: r = "MSG_DELETE_GUILD_CHARTER 	"; break;
            case 0x2C1: r = "MSG_PETITION_RENAME 	"; break;
            case 0x2C2: r = "SMSG_INIT_WORLD_STATES 	"; break;
            case 0x2C3: r = "SMSG_UPDATE_WORLD_STATE 	"; break;
            case 0x2C4: r = "CMSG_ITEM_NAME_QUERY 	"; break;
            case 0x2C5: r = "SMSG_ITEM_NAME_QUERY_RESPONSE 	"; break;
            case 0x2C6: r = "SMSG_PET_ACTION_FEEDBACK 	"; break;
            case 0x2C7: r = "CMSG_CHAR_RENAME 	"; break;
            case 0x2C8: r = "SMSG_CHAR_RENAME 	"; break;
            case 0x2C9: r = "CMSG_MOVE_SPLINE_DONE 	"; break;
            case 0x2CA: r = "CMSG_MOVE_FALL_RESET 	"; break;
            case 0x2CB: r = "SMSG_INSTANCE_SAVE_CREATED 	"; break;
            case 0x2CC: r = "SMSG_RAID_INSTANCE_INFO 	"; break;
            case 0x2CD: r = "CMSG_REQUEST_RAID_INFO 	"; break;
            case 0x2CE: r = "CMSG_MOVE_TIME_SKIPPED 	"; break;
            case 0x2CF: r = "CMSG_MOVE_FEATHER_FALL_ACK 	"; break;
            case 0x2D0: r = "CMSG_MOVE_WATER_WALK_ACK 	"; break;
            case 0x2D1: r = "CMSG_MOVE_NOT_ACTIVE_MOVER 	"; break;
            case 0x2D2: r = "SMSG_PLAY_SOUND 	"; break;
            case 0x2D3: r = "CMSG_BATTLEFIELD_STATUS 	"; break;
            case 0x2D4: r = "SMSG_BATTLEFIELD_STATUS 	"; break;
            case 0x2D5: r = "CMSG_BATTLEFIELD_PORT 	"; break;
            case 0x2D6: r = "MSG_INSPECT_HONOR_STATS 	"; break;
            case 0x2D7: r = "CMSG_BATTLEMASTER_HELLO 	"; break;
            case 0x2D8: r = "CMSG_MOVE_START_SWIM_CHEAT 	"; break;
            case 0x2D9: r = "CMSG_MOVE_STOP_SWIM_CHEAT 	"; break;
            case 0x2DA: r = "SMSG_FORCE_WALK_SPEED_CHANGE 	"; break;
            case 0x2DB: r = "CMSG_FORCE_WALK_SPEED_CHANGE_ACK 	"; break;
            case 0x2DC: r = "SMSG_FORCE_SWIM_BACK_SPEED_CHANGE 	"; break;
            case 0x2DD: r = "CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK 	"; break;
            case 0x2DE: r = "SMSG_FORCE_TURN_RATE_CHANGE 	"; break;
            case 0x2DF: r = "CMSG_FORCE_TURN_RATE_CHANGE_ACK 	"; break;
            case 0x2E0: r = "MSG_PVP_LOG_DATA 	"; break;
            case 0x2E1: r = "CMSG_LEAVE_BATTLEFIELD 	"; break;
            case 0x2E2: r = "CMSG_AREA_SPIRIT_HEALER_QUERY 	"; break;
            case 0x2E3: r = "CMSG_AREA_SPIRIT_HEALER_QUEUE 	"; break;
            case 0x2E4: r = "SMSG_AREA_SPIRIT_HEALER_TIME 	"; break;
            case 0x2E5: r = "CMSG_GM_UNTEACH 	"; break;
            case 0x2E6: r = "SMSG_WARDEN_DATA 	"; break;
            case 0x2E7: r = "CMSG_WARDEN_DATA 	"; break;
            case 0x2E8: r = "SMSG_GROUP_JOINED_BATTLEGROUND 	"; break;
            case 0x2E9: r = "MSG_BATTLEGROUND_PLAYER_POSITIONS 	"; break;
            case 0x2EA: r = "CMSG_PET_STOP_ATTACK 	"; break;
            case 0x2EB: r = "SMSG_BINDER_CONFIRM 	"; break;
            case 0x2EC: r = "SMSG_BATTLEGROUND_PLAYER_JOINED 	"; break;
            case 0x2ED: r = "SMSG_BATTLEGROUND_PLAYER_LEFT 	"; break;
            case 0x2EE: r = "CMSG_BATTLEMASTER_JOIN 	"; break;
            case 0x2EF: r = "SMSG_ADDON_INFO 	"; break;
            case 0x2F0: r = "CMSG_PET_UNLEARN 	"; break;
            case 0x2F1: r = "SMSG_PET_UNLEARN_CONFIRM 	"; break;
            case 0x2F2: r = "SMSG_PARTY_MEMBER_STATS_FULL 	"; break;
            case 0x2F3: r = "CMSG_PET_SPELL_AUTOCAST 	"; break;
            case 0x2F4: r = "SMSG_WEATHER 	"; break;
            case 0x2F5: r = "SMSG_PLAY_TIME_WARNING 	"; break;
            case 0x2F6: r = "SMSG_MINIGAME_SETUP 	"; break;
            case 0x2F7: r = "SMSG_MINIGAME_STATE 	"; break;
            case 0x2F8: r = "CMSG_MINIGAME_MOVE 	"; break;
            case 0x2F9: r = "SMSG_MINIGAME_MOVE_FAILED 	"; break;
            case 0x2FA: r = "SMSG_RAID_INSTANCE_MESSAGE 	"; break;
            case 0x2FB: r = "SMSG_COMPRESSED_MOVES 	"; break;
            case 0x2FC: r = "CMSG_GUILD_INFO_TEXT 	"; break;
            case 0x2FD: r = "SMSG_CHAT_RESTRICTED 	"; break;
            case 0x2FE: r = "SMSG_SPLINE_SET_RUN_SPEED 	"; break;
            case 0x2FF: r = "SMSG_SPLINE_SET_RUN_BACK_SPEED 	"; break;
            case 0x300: r = "SMSG_SPLINE_SET_SWIM_SPEED 	"; break;
            case 0x301: r = "SMSG_SPLINE_SET_WALK_SPEED 	"; break;
            case 0x302: r = "SMSG_SPLINE_SET_SWIM_BACK_SPEED 	"; break;
            case 0x303: r = "SMSG_SPLINE_SET_TURN_RATE 	"; break;
            case 0x304: r = "SMSG_SPLINE_MOVE_UNROOT 	"; break;
            case 0x305: r = "SMSG_SPLINE_MOVE_FEATHER_FALL 	"; break;
            case 0x306: r = "SMSG_SPLINE_MOVE_NORMAL_FALL 	"; break;
            case 0x307: r = "SMSG_SPLINE_MOVE_SET_HOVER 	"; break;
            case 0x308: r = "SMSG_SPLINE_MOVE_UNSET_HOVER 	"; break;
            case 0x309: r = "SMSG_SPLINE_MOVE_WATER_WALK 	"; break;
            case 0x30A: r = "SMSG_SPLINE_MOVE_LAND_WALK 	"; break;
            case 0x30B: r = "SMSG_SPLINE_MOVE_START_SWIM 	"; break;
            case 0x30C: r = "SMSG_SPLINE_MOVE_STOP_SWIM 	"; break;
            case 0x30D: r = "SMSG_SPLINE_MOVE_SET_RUN_MODE 	"; break;
            case 0x30E: r = "SMSG_SPLINE_MOVE_SET_WALK_MODE 	"; break;
            case 0x30F: r = "CMSG_GM_NUKE_ACCOUNT 	"; break;
            case 0x310: r = "MSG_GM_DESTROY_CORPSE 	"; break;
            case 0x311: r = "CMSG_GM_DESTROY_ONLINE_CORPSE 	"; break;
            case 0x312: r = "CMSG_ACTIVATETAXIEXPRESS 	"; break;
            case 0x313: r = "SMSG_SET_FACTION_ATWAR 	"; break;
            case 0x314: r = "SMSG_GAMETIMEBIAS_SET 	"; break;
            case 0x315: r = "CMSG_DEBUG_ACTIONS_START 	"; break;
            case 0x316: r = "CMSG_DEBUG_ACTIONS_STOP 	"; break;
            case 0x317: r = "CMSG_SET_FACTION_INACTIVE 	"; break;
            case 0x318: r = "CMSG_SET_WATCHED_FACTION 	"; break;
            case 0x319: r = "MSG_MOVE_TIME_SKIPPED 	"; break;
            case 0x31A: r = "SMSG_SPLINE_MOVE_ROOT 	"; break;
            case 0x31B: r = "CMSG_SET_EXPLORATION_ALL 	"; break;
            case 0x31C: r = "SMSG_INVALIDATE_PLAYER 	"; break;
            case 0x31D: r = "CMSG_RESET_INSTANCES 	"; break;
            case 0x31E: r = "SMSG_INSTANCE_RESET 	"; break;
            case 0x31F: r = "SMSG_INSTANCE_RESET_FAILED 	"; break;
            case 0x320: r = "SMSG_UPDATE_LAST_INSTANCE 	"; break;
            case 0x321: r = "MSG_RAID_TARGET_UPDATE 	"; break;
            case 0x322: r = "MSG_RAID_READY_CHECK 	"; break;
            case 0x323: r = "CMSG_LUA_USAGE 	"; break;
            case 0x324: r = "SMSG_PET_ACTION_SOUND 	"; break;
            case 0x325: r = "SMSG_PET_DISMISS_SOUND 	"; break;
            case 0x326: r = "SMSG_GHOSTEE_GONE 	"; break;
            case 0x327: r = "CMSG_GM_UPDATE_TICKET_STATUS 	"; break;
            case 0x328: r = "SMSG_GM_TICKET_STATUS_UPDATE 	"; break;
            case 0x32A: r = "CMSG_GMSURVEY_SUBMIT 	"; break;
            case 0x32B: r = "SMSG_UPDATE_INSTANCE_OWNERSHIP 	"; break;
            case 0x32C: r = "CMSG_IGNORE_KNOCKBACK_CHEAT 	"; break;
            case 0x32D: r = "SMSG_CHAT_PLAYER_AMBIGUOUS 	"; break;
            case 0x32E: r = "MSG_DELAY_GHOST_TELEPORT 	"; break;
            case 0x32F: r = "SMSG_SPELLINSTAKILLLOG 	"; break;
            case 0x330: r = "SMSG_SPELL_UPDATE_CHAIN_TARGETS 	"; break;
            case 0x331: r = "CMSG_CHAT_FILTERED 	"; break;
            case 0x332: r = "SMSG_EXPECTED_SPAM_RECORDS 	"; break;
            case 0x333: r = "SMSG_SPELLSTEALLOG 	"; break;
            case 0x334: r = "CMSG_LOTTERY_QUERY_OBSOLETE 	"; break;
            case 0x335: r = "SMSG_LOTTERY_QUERY_RESULT_OBSOLETE 	"; break;
            case 0x336: r = "CMSG_BUY_LOTTERY_TICKET_OBSOLETE 	"; break;
            case 0x337: r = "SMSG_LOTTERY_RESULT_OBSOLETE 	"; break;
            case 0x338: r = "SMSG_CHARACTER_PROFILE 	"; break;
            case 0x339: r = "SMSG_CHARACTER_PROFILE_REALM_CONNECTED 	"; break;
            case 0x33B: r = "SMSG_DEFENSE_MESSAGE 	"; break;
            case 0x33C: r = "NUM_MSG_TYPES 	"; break;


            default: r = "unknown";
        }
    enum OpcodesList
    {

            CMSG_GUILD_LEADER = 0x090,
            CMSG_GUILD_MOTD = 0x091,
            SMSG_GUILD_EVENT = 0x092,
            SMSG_GUILD_COMMAND_RESULT = 0x093,
            MSG_UPDATE_GUILD = 0x094,
            CMSG_MESSAGECHAT = 0x095,
            SMSG_MESSAGECHAT = 0x096,
            CMSG_JOIN_CHANNEL = 0x097,
            CMSG_LEAVE_CHANNEL = 0x098,
            SMSG_CHANNEL_NOTIFY = 0x099,
            CMSG_CHANNEL_LIST = 0x09A,
            SMSG_CHANNEL_LIST = 0x09B,
            CMSG_CHANNEL_PASSWORD = 0x09C,
            CMSG_CHANNEL_SET_OWNER = 0x09D,
            CMSG_CHANNEL_OWNER = 0x09E,
            CMSG_CHANNEL_MODERATOR = 0x09F,
            CMSG_CHANNEL_UNMODERATOR = 0x0A0,
            CMSG_CHANNEL_MUTE = 0x0A1,
            CMSG_CHANNEL_UNMUTE = 0x0A2,
            CMSG_CHANNEL_INVITE = 0x0A3,
            CMSG_CHANNEL_KICK = 0x0A4,
            CMSG_CHANNEL_BAN = 0x0A5,
            CMSG_CHANNEL_UNBAN = 0x0A6,
            CMSG_CHANNEL_ANNOUNCEMENTS = 0x0A7,
            CMSG_CHANNEL_MODERATE = 0x0A8,
            SMSG_UPDATE_OBJECT = 0x0A9,
            SMSG_DESTROY_OBJECT = 0x0AA,
            CMSG_USE_ITEM = 0x0AB,
            CMSG_OPEN_ITEM = 0x0AC,
            CMSG_READ_ITEM = 0x0AD,
            SMSG_READ_ITEM_OK = 0x0AE,
            SMSG_READ_ITEM_FAILED = 0x0AF,
            SMSG_ITEM_COOLDOWN = 0x0B0,
            CMSG_GAMEOBJ_USE = 0x0B1,
            CMSG_GAMEOBJ_CHAIR_USE_OBSOLETE = 0x0B2,
            SMSG_GAMEOBJECT_CUSTOM_ANIM = 0x0B3,
            CMSG_AREATRIGGER = 0x0B4,
            MSG_MOVE_START_FORWARD = 0x0B5,
            MSG_MOVE_START_BACKWARD = 0x0B6,
            MSG_MOVE_STOP = 0x0B7,
            MSG_MOVE_START_STRAFE_LEFT = 0x0B8,
            MSG_MOVE_START_STRAFE_RIGHT = 0x0B9,
            MSG_MOVE_STOP_STRAFE = 0x0BA,
            MSG_MOVE_JUMP = 0x0BB,
            MSG_MOVE_START_TURN_LEFT = 0x0BC,
            MSG_MOVE_START_TURN_RIGHT = 0x0BD,
            MSG_MOVE_STOP_TURN = 0x0BE,
            MSG_MOVE_START_PITCH_UP = 0x0BF,
            MSG_MOVE_START_PITCH_DOWN = 0x0C0,
            MSG_MOVE_STOP_PITCH = 0x0C1,
            MSG_MOVE_SET_RUN_MODE = 0x0C2,
            MSG_MOVE_SET_WALK_MODE = 0x0C3,
            MSG_MOVE_TOGGLE_LOGGING = 0x0C4,
            MSG_MOVE_TELEPORT = 0x0C5,
            MSG_MOVE_TELEPORT_CHEAT = 0x0C6,
            MSG_MOVE_TELEPORT_ACK = 0x0C7,
            MSG_MOVE_TOGGLE_FALL_LOGGING = 0x0C8,
            MSG_MOVE_FALL_LAND = 0x0C9,
            MSG_MOVE_START_SWIM = 0x0CA,
            MSG_MOVE_STOP_SWIM = 0x0CB,
            MSG_MOVE_SET_RUN_SPEED_CHEAT = 0x0CC,
            MSG_MOVE_SET_RUN_SPEED = 0x0CD,
            MSG_MOVE_SET_RUN_BACK_SPEED_CHEAT = 0x0CE,
            MSG_MOVE_SET_RUN_BACK_SPEED = 0x0CF,
            MSG_MOVE_SET_WALK_SPEED_CHEAT = 0x0D0,
            MSG_MOVE_SET_WALK_SPEED = 0x0D1,
            MSG_MOVE_SET_SWIM_SPEED_CHEAT = 0x0D2,
            MSG_MOVE_SET_SWIM_SPEED = 0x0D3,
            MSG_MOVE_SET_SWIM_BACK_SPEED_CHEAT = 0x0D4,
            MSG_MOVE_SET_SWIM_BACK_SPEED = 0x0D5,
            MSG_MOVE_SET_ALL_SPEED_CHEAT = 0x0D6,
            MSG_MOVE_SET_TURN_RATE_CHEAT = 0x0D7,
            MSG_MOVE_SET_TURN_RATE = 0x0D8,
            MSG_MOVE_TOGGLE_COLLISION_CHEAT = 0x0D9,
            MSG_MOVE_SET_FACING = 0x0DA,
            MSG_MOVE_SET_PITCH = 0x0DB,
            MSG_MOVE_WORLDPORT_ACK = 0x0DC,
            SMSG_MONSTER_MOVE = 0x0DD,
            SMSG_MOVE_WATER_WALK = 0x0DE,
            SMSG_MOVE_LAND_WALK = 0x0DF,
            MSG_MOVE_SET_RAW_POSITION_ACK = 0x0E0,
            CMSG_MOVE_SET_RAW_POSITION = 0x0E1,
            SMSG_FORCE_RUN_SPEED_CHANGE = 0x0E2,
            CMSG_FORCE_RUN_SPEED_CHANGE_ACK = 0x0E3,
            SMSG_FORCE_RUN_BACK_SPEED_CHANGE = 0x0E4,
            CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK = 0x0E5,
            SMSG_FORCE_SWIM_SPEED_CHANGE = 0x0E6,
            CMSG_FORCE_SWIM_SPEED_CHANGE_ACK = 0x0E7,
            SMSG_FORCE_MOVE_ROOT = 0x0E8,
            CMSG_FORCE_MOVE_ROOT_ACK = 0x0E9,
            SMSG_FORCE_MOVE_UNROOT = 0x0EA,
            CMSG_FORCE_MOVE_UNROOT_ACK = 0x0EB,
            MSG_MOVE_ROOT = 0x0EC,
            MSG_MOVE_UNROOT = 0x0ED,
            MSG_MOVE_HEARTBEAT = 0x0EE,
            SMSG_MOVE_KNOCK_BACK = 0x0EF,
            CMSG_MOVE_KNOCK_BACK_ACK = 0x0F0,
            MSG_MOVE_KNOCK_BACK = 0x0F1,
            SMSG_MOVE_FEATHER_FALL = 0x0F2,
            SMSG_MOVE_NORMAL_FALL = 0x0F3,
            SMSG_MOVE_SET_HOVER = 0x0F4,
            SMSG_MOVE_UNSET_HOVER = 0x0F5,
            CMSG_MOVE_HOVER_ACK = 0x0F6,
            MSG_MOVE_HOVER = 0x0F7,
            CMSG_TRIGGER_CINEMATIC_CHEAT = 0x0F8,
            CMSG_OPENING_CINEMATIC = 0x0F9,
            SMSG_TRIGGER_CINEMATIC = 0x0FA,
            CMSG_NEXT_CINEMATIC_CAMERA = 0x0FB,
            CMSG_COMPLETE_CINEMATIC = 0x0FC,
            SMSG_TUTORIAL_FLAGS = 0x0FD,
            CMSG_TUTORIAL_FLAG = 0x0FE,
            CMSG_TUTORIAL_CLEAR = 0x0FF,
            CMSG_TUTORIAL_RESET = 0x100,
            CMSG_STANDSTATECHANGE = 0x101,
            CMSG_EMOTE = 0x102,
            SMSG_EMOTE = 0x103,
            CMSG_TEXT_EMOTE = 0x104,
            SMSG_TEXT_EMOTE = 0x105,
            CMSG_AUTOEQUIP_GROUND_ITEM = 0x106,
            CMSG_AUTOSTORE_GROUND_ITEM = 0x107,
            CMSG_AUTOSTORE_LOOT_ITEM = 0x108,
            CMSG_STORE_LOOT_IN_SLOT = 0x109,
            CMSG_AUTOEQUIP_ITEM = 0x10A,
            CMSG_AUTOSTORE_BAG_ITEM = 0x10B,
            CMSG_SWAP_ITEM = 0x10C,
            CMSG_SWAP_INV_ITEM = 0x10D,
            CMSG_SPLIT_ITEM = 0x10E,
            CMSG_AUTOEQUIP_ITEM_SLOT = 0x10F,
            CMSG_DROP_ITEM = 0x110,
            CMSG_DESTROYITEM = 0x111,
            SMSG_INVENTORY_CHANGE_FAILURE = 0x112,
            SMSG_OPEN_CONTAINER = 0x113,
            CMSG_INSPECT = 0x114,
            SMSG_INSPECT = 0x115,
            CMSG_INITIATE_TRADE = 0x116,
            CMSG_BEGIN_TRADE = 0x117,
            CMSG_BUSY_TRADE = 0x118,
            CMSG_IGNORE_TRADE = 0x119,
            CMSG_ACCEPT_TRADE = 0x11A,
            CMSG_UNACCEPT_TRADE = 0x11B,
            CMSG_CANCEL_TRADE = 0x11C,
            CMSG_SET_TRADE_ITEM = 0x11D,
            CMSG_CLEAR_TRADE_ITEM = 0x11E,
            CMSG_SET_TRADE_GOLD = 0x11F,
            SMSG_TRADE_STATUS = 0x120,
            SMSG_TRADE_STATUS_EXTENDED = 0x121,
            SMSG_INITIALIZE_FACTIONS = 0x122,
            SMSG_SET_FACTION_VISIBLE = 0x123,
            SMSG_SET_FACTION_STANDING = 0x124,
            CMSG_SET_FACTION_ATWAR = 0x125,
            CMSG_SET_FACTION_CHEAT = 0x126,
            SMSG_SET_PROFICIENCY = 0x127,
            CMSG_SET_ACTION_BUTTON = 0x128,
            SMSG_ACTION_BUTTONS = 0x129,
            SMSG_INITIAL_SPELLS = 0x12A,
            SMSG_LEARNED_SPELL = 0x12B,
            SMSG_SUPERCEDED_SPELL = 0x12C,
            CMSG_NEW_SPELL_SLOT = 0x12D,
            CMSG_CAST_SPELL = 0x12E,
            CMSG_CANCEL_CAST = 0x12F,
            SMSG_CAST_RESULT = 0x130,
            SMSG_SPELL_START = 0x131,
            SMSG_SPELL_GO = 0x132,
            SMSG_SPELL_FAILURE = 0x133,
            SMSG_SPELL_COOLDOWN = 0x134,
            SMSG_COOLDOWN_EVENT = 0x135,
            CMSG_CANCEL_AURA = 0x136,
            SMSG_UPDATE_AURA_DURATION = 0x137,
            SMSG_PET_CAST_FAILED = 0x138,
            MSG_CHANNEL_START = 0x139,
            MSG_CHANNEL_UPDATE = 0x13A,
            CMSG_CANCEL_CHANNELLING = 0x13B,
            SMSG_AI_REACTION = 0x13C,
            CMSG_SET_SELECTION = 0x13D,
            CMSG_SET_TARGET_OBSOLETE = 0x13E,
            CMSG_UNUSED = 0x13F,
            CMSG_UNUSED2 = 0x140,
            CMSG_ATTACKSWING = 0x141,
            CMSG_ATTACKSTOP = 0x142,
            SMSG_ATTACKSTART = 0x143,
            SMSG_ATTACKSTOP = 0x144,
            SMSG_ATTACKSWING_NOTINRANGE = 0x145,
            SMSG_ATTACKSWING_BADFACING = 0x146,
            SMSG_ATTACKSWING_NOTSTANDING = 0x147,
            SMSG_ATTACKSWING_DEADTARGET = 0x148,
            SMSG_ATTACKSWING_CANT_ATTACK = 0x149,
            SMSG_ATTACKERSTATEUPDATE = 0x14A,
            SMSG_VICTIMSTATEUPDATE_OBSOLETE = 0x14B,
            SMSG_DAMAGE_DONE_OBSOLETE = 0x14C,
            SMSG_DAMAGE_TAKEN_OBSOLETE = 0x14D,
            SMSG_CANCEL_COMBAT = 0x14E,
            SMSG_PLAYER_COMBAT_XP_GAIN_OBSOLETE = 0x14F,
            SMSG_SPELLHEALLOG = 0x150,
            SMSG_SPELLENERGIZELOG = 0x151,
            CMSG_SHEATHE_OBSOLETE = 0x152,
            CMSG_SAVE_PLAYER = 0x153,
            CMSG_SETDEATHBINDPOINT = 0x154,
            SMSG_BINDPOINTUPDATE = 0x155,
            CMSG_GETDEATHBINDZONE = 0x156,
            SMSG_BINDZONEREPLY = 0x157,
            SMSG_PLAYERBOUND = 0x158,
            SMSG_CLIENT_CONTROL_UPDATE = 0x159,
            CMSG_REPOP_REQUEST = 0x15A,
            SMSG_RESURRECT_REQUEST = 0x15B,
            CMSG_RESURRECT_RESPONSE = 0x15C,
            CMSG_LOOT = 0x15D,
            CMSG_LOOT_MONEY = 0x15E,
            CMSG_LOOT_RELEASE = 0x15F,
            SMSG_LOOT_RESPONSE = 0x160,
            SMSG_LOOT_RELEASE_RESPONSE = 0x161,
            SMSG_LOOT_REMOVED = 0x162,
            SMSG_LOOT_MONEY_NOTIFY = 0x163,
            SMSG_LOOT_ITEM_NOTIFY = 0x164,
            SMSG_LOOT_CLEAR_MONEY = 0x165,
            SMSG_ITEM_PUSH_RESULT = 0x166,
            SMSG_DUEL_REQUESTED = 0x167,
            SMSG_DUEL_OUTOFBOUNDS = 0x168,
            SMSG_DUEL_INBOUNDS = 0x169,
            SMSG_DUEL_COMPLETE = 0x16A,
            SMSG_DUEL_WINNER = 0x16B,
            CMSG_DUEL_ACCEPTED = 0x16C,
            CMSG_DUEL_CANCELLED = 0x16D,
            SMSG_MOUNTRESULT = 0x16E,
            SMSG_DISMOUNTRESULT = 0x16F,
            SMSG_PUREMOUNT_CANCELLED_OBSOLETE = 0x170,
            CMSG_MOUNTSPECIAL_ANIM = 0x171,
            SMSG_MOUNTSPECIAL_ANIM = 0x172,
            SMSG_PET_TAME_FAILURE = 0x173,
            CMSG_PET_SET_ACTION = 0x174,
            CMSG_PET_ACTION = 0x175,
            CMSG_PET_ABANDON = 0x176,
            CMSG_PET_RENAME = 0x177,
            SMSG_PET_NAME_INVALID = 0x178,
            SMSG_PET_SPELLS = 0x179,
            SMSG_PET_MODE = 0x17A,
            CMSG_GOSSIP_HELLO = 0x17B,
            CMSG_GOSSIP_SELECT_OPTION = 0x17C,
            SMSG_GOSSIP_MESSAGE = 0x17D,
            SMSG_GOSSIP_COMPLETE = 0x17E,
            CMSG_NPC_TEXT_QUERY = 0x17F,
            SMSG_NPC_TEXT_UPDATE = 0x180,
            SMSG_NPC_WONT_TALK = 0x181,
            CMSG_QUESTGIVER_STATUS_QUERY = 0x182,
            SMSG_QUESTGIVER_STATUS = 0x183,
            CMSG_QUESTGIVER_HELLO = 0x184,
            SMSG_QUESTGIVER_QUEST_LIST = 0x185,
            CMSG_QUESTGIVER_QUERY_QUEST = 0x186,
            CMSG_QUESTGIVER_QUEST_AUTOLAUNCH = 0x187,
            SMSG_QUESTGIVER_QUEST_DETAILS = 0x188,
            CMSG_QUESTGIVER_ACCEPT_QUEST = 0x189,
            CMSG_QUESTGIVER_COMPLETE_QUEST = 0x18A,
            SMSG_QUESTGIVER_REQUEST_ITEMS = 0x18B,
            CMSG_QUESTGIVER_REQUEST_REWARD = 0x18C,
            SMSG_QUESTGIVER_OFFER_REWARD = 0x18D,
            CMSG_QUESTGIVER_CHOOSE_REWARD = 0x18E,
            SMSG_QUESTGIVER_QUEST_INVALID = 0x18F,
            CMSG_QUESTGIVER_CANCEL = 0x190,
            SMSG_QUESTGIVER_QUEST_COMPLETE = 0x191,
            SMSG_QUESTGIVER_QUEST_FAILED = 0x192,
            CMSG_QUESTLOG_SWAP_QUEST = 0x193,
            CMSG_QUESTLOG_REMOVE_QUEST = 0x194,
            SMSG_QUESTLOG_FULL = 0x195,
            SMSG_QUESTUPDATE_FAILED = 0x196,
            SMSG_QUESTUPDATE_FAILEDTIMER = 0x197,
            SMSG_QUESTUPDATE_COMPLETE = 0x198,
            SMSG_QUESTUPDATE_ADD_KILL = 0x199,
            SMSG_QUESTUPDATE_ADD_ITEM = 0x19A,
            CMSG_QUEST_CONFIRM_ACCEPT = 0x19B,
            SMSG_QUEST_CONFIRM_ACCEPT = 0x19C,
            CMSG_PUSHQUESTTOPARTY = 0x19D,
            CMSG_LIST_INVENTORY = 0x19E,
            SMSG_LIST_INVENTORY = 0x19F,
            CMSG_SELL_ITEM = 0x1A0,
            SMSG_SELL_ITEM = 0x1A1,
            CMSG_BUY_ITEM = 0x1A2,
            CMSG_BUY_ITEM_IN_SLOT = 0x1A3,
            SMSG_BUY_ITEM = 0x1A4,
            SMSG_BUY_FAILED = 0x1A5,
            CMSG_TAXICLEARALLNODES = 0x1A6,
            CMSG_TAXIENABLEALLNODES = 0x1A7,
            CMSG_TAXISHOWNODES = 0x1A8,
            SMSG_SHOWTAXINODES = 0x1A9,
            CMSG_TAXINODE_STATUS_QUERY = 0x1AA,
            SMSG_TAXINODE_STATUS = 0x1AB,
            CMSG_TAXIQUERYAVAILABLENODES = 0x1AC,
            CMSG_ACTIVATETAXI = 0x1AD,
            SMSG_ACTIVATETAXIREPLY = 0x1AE,
            SMSG_NEW_TAXI_PATH = 0x1AF,
            CMSG_TRAINER_LIST = 0x1B0,
            SMSG_TRAINER_LIST = 0x1B1,
            CMSG_TRAINER_BUY_SPELL = 0x1B2,
            SMSG_TRAINER_BUY_SUCCEEDED = 0x1B3,
            SMSG_TRAINER_BUY_FAILED = 0x1B4, // uint64, uint32, uint32 (0...2)
            CMSG_BINDER_ACTIVATE = 0x1B5,
            SMSG_PLAYERBINDERROR = 0x1B6,
            CMSG_BANKER_ACTIVATE = 0x1B7,
            SMSG_SHOW_BANK = 0x1B8,
            CMSG_BUY_BANK_SLOT = 0x1B9,
            SMSG_BUY_BANK_SLOT_RESULT = 0x1BA,
            CMSG_PETITION_SHOWLIST = 0x1BB,
            SMSG_PETITION_SHOWLIST = 0x1BC,
            CMSG_PETITION_BUY = 0x1BD,
            CMSG_PETITION_SHOW_SIGNATURES = 0x1BE,
            SMSG_PETITION_SHOW_SIGNATURES = 0x1BF,
            CMSG_PETITION_SIGN = 0x1C0,
            SMSG_PETITION_SIGN_RESULTS = 0x1C1,
            MSG_PETITION_DECLINE = 0x1C2,
            CMSG_OFFER_PETITION = 0x1C3,
            CMSG_TURN_IN_PETITION = 0x1C4,
            SMSG_TURN_IN_PETITION_RESULTS = 0x1C5,
            CMSG_PETITION_QUERY = 0x1C6,
            SMSG_PETITION_QUERY_RESPONSE = 0x1C7,
            SMSG_FISH_NOT_HOOKED = 0x1C8,
            SMSG_FISH_ESCAPED = 0x1C9,
            CMSG_BUG = 0x1CA,
            SMSG_NOTIFICATION = 0x1CB,
            CMSG_PLAYED_TIME = 0x1CC,
            SMSG_PLAYED_TIME = 0x1CD,
            CMSG_QUERY_TIME = 0x1CE,
            SMSG_QUERY_TIME_RESPONSE = 0x1CF,
            SMSG_LOG_XPGAIN = 0x1D0,
            SMSG_AURACASTLOG = 0x1D1,
            CMSG_RECLAIM_CORPSE = 0x1D2,
            CMSG_WRAP_ITEM = 0x1D3,
            SMSG_LEVELUP_INFO = 0x1D4,
            MSG_MINIMAP_PING = 0x1D5,
            SMSG_RESISTLOG = 0x1D6,
            SMSG_ENCHANTMENTLOG = 0x1D7,
            CMSG_SET_SKILL_CHEAT = 0x1D8,
            SMSG_START_MIRROR_TIMER = 0x1D9,
            SMSG_PAUSE_MIRROR_TIMER = 0x1DA,
            SMSG_STOP_MIRROR_TIMER = 0x1DB,
            CMSG_PING = 0x1DC,
            SMSG_PONG = 0x1DD,
            SMSG_CLEAR_COOLDOWN = 0x1DE,
            SMSG_GAMEOBJECT_PAGETEXT = 0x1DF,
            CMSG_SETSHEATHED = 0x1E0,
            SMSG_COOLDOWN_CHEAT = 0x1E1,
            SMSG_SPELL_DELAYED = 0x1E2,
            CMSG_PLAYER_MACRO_OBSOLETE = 0x1E3,
            SMSG_PLAYER_MACRO_OBSOLETE = 0x1E4,
            CMSG_GHOST = 0x1E5,
            CMSG_GM_INVIS = 0x1E6,
            SMSG_INVALID_PROMOTION_CODE = 0x1E7,
            MSG_GM_BIND_OTHER = 0x1E8,
            MSG_GM_SUMMON = 0x1E9,
            SMSG_ITEM_TIME_UPDATE = 0x1EA,
            SMSG_ITEM_ENCHANT_TIME_UPDATE = 0x1EB,
            SMSG_AUTH_CHALLENGE = 0x1EC,
            CMSG_AUTH_SESSION = 0x1ED,
            SMSG_AUTH_RESPONSE = 0x1EE,
            MSG_GM_SHOWLABEL = 0x1EF,
            CMSG_PET_CAST_SPELL = 0x1F0,
            MSG_SAVE_GUILD_EMBLEM = 0x1F1,
            MSG_TABARDVENDOR_ACTIVATE = 0x1F2,
            SMSG_PLAY_SPELL_VISUAL = 0x1F3,
            CMSG_ZONEUPDATE = 0x1F4,
            SMSG_PARTYKILLLOG = 0x1F5,
            SMSG_COMPRESSED_UPDATE_OBJECT = 0x1F6,
            SMSG_PLAY_SPELL_IMPACT = 0x1F7,
            SMSG_EXPLORATION_EXPERIENCE = 0x1F8,
            CMSG_GM_SET_SECURITY_GROUP = 0x1F9,
            CMSG_GM_NUKE = 0x1FA,
            MSG_RANDOM_ROLL = 0x1FB,
            SMSG_ENVIRONMENTALDAMAGELOG = 0x1FC,
            CMSG_RWHOIS = 0x1FD,
            SMSG_RWHOIS = 0x1FE,
            MSG_LOOKING_FOR_GROUP = 0x1FF,
            CMSG_SET_LOOKING_FOR_GROUP = 0x200,
            CMSG_UNLEARN_SPELL = 0x201,
            CMSG_UNLEARN_SKILL = 0x202,
            SMSG_REMOVED_SPELL = 0x203,
            CMSG_DECHARGE = 0x204,
            CMSG_GMTICKET_CREATE = 0x205,
            SMSG_GMTICKET_CREATE = 0x206,
            CMSG_GMTICKET_UPDATETEXT = 0x207,
            SMSG_GMTICKET_UPDATETEXT = 0x208,
            SMSG_ACCOUNT_DATA_TIMES = 0x209,
            CMSG_REQUEST_ACCOUNT_DATA = 0x20A,
            CMSG_UPDATE_ACCOUNT_DATA = 0x20B,
            SMSG_UPDATE_ACCOUNT_DATA = 0x20C,
            SMSG_CLEAR_FAR_SIGHT_IMMEDIATE = 0x20D,
            SMSG_POWERGAINLOG_OBSOLETE = 0x20E,
            CMSG_GM_TEACH = 0x20F,
            CMSG_GM_CREATE_ITEM_TARGET = 0x210,
            CMSG_GMTICKET_GETTICKET = 0x211,
            SMSG_GMTICKET_GETTICKET = 0x212,
            CMSG_UNLEARN_TALENTS = 0x213,
            SMSG_GAMEOBJECT_SPAWN_ANIM = 0x214,
            SMSG_GAMEOBJECT_DESPAWN_ANIM = 0x215,
            MSG_CORPSE_QUERY = 0x216,
            CMSG_GMTICKET_DELETETICKET = 0x217,
            SMSG_GMTICKET_DELETETICKET = 0x218,
            SMSG_CHAT_WRONG_FACTION = 0x219,
            CMSG_GMTICKET_SYSTEMSTATUS = 0x21A,
            SMSG_GMTICKET_SYSTEMSTATUS = 0x21B,
            CMSG_SPIRIT_HEALER_ACTIVATE = 0x21C,
            CMSG_SET_STAT_CHEAT = 0x21D,
            SMSG_SET_REST_START = 0x21E,
            CMSG_SKILL_BUY_STEP = 0x21F,
            CMSG_SKILL_BUY_RANK = 0x220,
            CMSG_XP_CHEAT = 0x221,
            SMSG_SPIRIT_HEALER_CONFIRM = 0x222,
            CMSG_CHARACTER_POINT_CHEAT = 0x223,
            SMSG_GOSSIP_POI = 0x224,
            CMSG_CHAT_IGNORED = 0x225,
            CMSG_GM_VISION = 0x226,
            CMSG_SERVER_COMMAND = 0x227,
            CMSG_GM_SILENCE = 0x228,
            CMSG_GM_REVEALTO = 0x229,
            CMSG_GM_RESURRECT = 0x22A,
            CMSG_GM_SUMMONMOB = 0x22B,
            CMSG_GM_MOVECORPSE = 0x22C,
            CMSG_GM_FREEZE = 0x22D,
            CMSG_GM_UBERINVIS = 0x22E,
            CMSG_GM_REQUEST_PLAYER_INFO = 0x22F,
            SMSG_GM_PLAYER_INFO = 0x230,
            CMSG_GUILD_RANK = 0x231,
            CMSG_GUILD_ADD_RANK = 0x232,
            CMSG_GUILD_DEL_RANK = 0x233,
            CMSG_GUILD_SET_PUBLIC_NOTE = 0x234,
            CMSG_GUILD_SET_OFFICER_NOTE = 0x235,
            SMSG_LOGIN_VERIFY_WORLD = 0x236,
            CMSG_CLEAR_EXPLORATION = 0x237,
            CMSG_SEND_MAIL = 0x238,
            SMSG_SEND_MAIL_RESULT = 0x239,
            CMSG_GET_MAIL_LIST = 0x23A,
            SMSG_MAIL_LIST_RESULT = 0x23B,
            CMSG_BATTLEFIELD_LIST = 0x23C,
            SMSG_BATTLEFIELD_LIST = 0x23D,
            CMSG_BATTLEFIELD_JOIN = 0x23E,
            SMSG_BATTLEFIELD_WIN = 0x23F,
            SMSG_BATTLEFIELD_LOSE = 0x240,
            CMSG_TAXICLEARNODE = 0x241,
            CMSG_TAXIENABLENODE = 0x242,
            CMSG_ITEM_TEXT_QUERY = 0x243,
            SMSG_ITEM_TEXT_QUERY_RESPONSE = 0x244,
            CMSG_MAIL_TAKE_MONEY = 0x245,
            CMSG_MAIL_TAKE_ITEM = 0x246,
            CMSG_MAIL_MARK_AS_READ = 0x247,
            CMSG_MAIL_RETURN_TO_SENDER = 0x248,
            CMSG_MAIL_DELETE = 0x249,
            CMSG_MAIL_CREATE_TEXT_ITEM = 0x24A,
            SMSG_SPELLLOGMISS = 0x24B,
            SMSG_SPELLLOGEXECUTE = 0x24C,
            SMSG_DEBUGAURAPROC = 0x24D,
            SMSG_PERIODICAURALOG = 0x24E,
            SMSG_SPELLDAMAGESHIELD = 0x24F,
            SMSG_SPELLNONMELEEDAMAGELOG = 0x250,
            CMSG_LEARN_TALENT = 0x251,
            SMSG_RESURRECT_FAILED = 0x252,
            CMSG_TOGGLE_PVP = 0x253,
            SMSG_ZONE_UNDER_ATTACK = 0x254,
            MSG_AUCTION_HELLO = 0x255,
            CMSG_AUCTION_SELL_ITEM = 0x256,
            CMSG_AUCTION_REMOVE_ITEM = 0x257,
            CMSG_AUCTION_LIST_ITEMS = 0x258,
            CMSG_AUCTION_LIST_OWNER_ITEMS = 0x259,
            CMSG_AUCTION_PLACE_BID = 0x25A,
            SMSG_AUCTION_COMMAND_RESULT = 0x25B,
            SMSG_AUCTION_LIST_RESULT = 0x25C,
            SMSG_AUCTION_OWNER_LIST_RESULT = 0x25D,
            SMSG_AUCTION_BIDDER_NOTIFICATION = 0x25E,
            SMSG_AUCTION_OWNER_NOTIFICATION = 0x25F,
            SMSG_PROCRESIST = 0x260,
            SMSG_STANDSTATE_CHANGE_FAILURE = 0x261,
            SMSG_DISPEL_FAILED = 0x262,
            SMSG_SPELLORDAMAGE_IMMUNE = 0x263,
            CMSG_AUCTION_LIST_BIDDER_ITEMS = 0x264,
            SMSG_AUCTION_BIDDER_LIST_RESULT = 0x265,
            SMSG_SET_FLAT_SPELL_MODIFIER = 0x266,
            SMSG_SET_PCT_SPELL_MODIFIER = 0x267,
            CMSG_SET_AMMO = 0x268,
            SMSG_CORPSE_RECLAIM_DELAY = 0x269,
            CMSG_SET_ACTIVE_MOVER = 0x26A,
            CMSG_PET_CANCEL_AURA = 0x26B,
            CMSG_PLAYER_AI_CHEAT = 0x26C,
            CMSG_CANCEL_AUTO_REPEAT_SPELL = 0x26D,
            MSG_GM_ACCOUNT_ONLINE = 0x26E,
            MSG_LIST_STABLED_PETS = 0x26F,
            CMSG_STABLE_PET = 0x270,
            CMSG_UNSTABLE_PET = 0x271,
            CMSG_BUY_STABLE_SLOT = 0x272,
            SMSG_STABLE_RESULT = 0x273,
            CMSG_STABLE_REVIVE_PET = 0x274,
            CMSG_STABLE_SWAP_PET = 0x275,
            MSG_QUEST_PUSH_RESULT = 0x276,
            SMSG_PLAY_MUSIC = 0x277,
            SMSG_PLAY_OBJECT_SOUND = 0x278,
            CMSG_REQUEST_PET_INFO = 0x279,
            CMSG_FAR_SIGHT = 0x27A,
            SMSG_SPELLDISPELLOG = 0x27B,
            SMSG_DAMAGE_CALC_LOG = 0x27C,
            CMSG_ENABLE_DAMAGE_LOG = 0x27D,
            CMSG_GROUP_CHANGE_SUB_GROUP = 0x27E,
            CMSG_REQUEST_PARTY_MEMBER_STATS = 0x27F,
            CMSG_GROUP_SWAP_SUB_GROUP = 0x280,
            CMSG_RESET_FACTION_CHEAT = 0x281,
            CMSG_AUTOSTORE_BANK_ITEM = 0x282,
            CMSG_AUTOBANK_ITEM = 0x283,
            MSG_QUERY_NEXT_MAIL_TIME = 0x284,
            SMSG_RECEIVED_MAIL = 0x285,
            SMSG_RAID_GROUP_ONLY = 0x286,
            CMSG_SET_DURABILITY_CHEAT = 0x287,
            CMSG_SET_PVP_RANK_CHEAT = 0x288,
            CMSG_ADD_PVP_MEDAL_CHEAT = 0x289,
            CMSG_DEL_PVP_MEDAL_CHEAT = 0x28A,
            CMSG_SET_PVP_TITLE = 0x28B,
            SMSG_PVP_CREDIT = 0x28C,
            SMSG_AUCTION_REMOVED_NOTIFICATION = 0x28D,
            CMSG_GROUP_RAID_CONVERT = 0x28E,
            CMSG_GROUP_ASSISTANT_LEADER = 0x28F,
            CMSG_BUYBACK_ITEM = 0x290,
            SMSG_SERVER_MESSAGE = 0x291,
            CMSG_MEETINGSTONE_JOIN = 0x292, // lua: SetSavedInstanceExtend
            CMSG_MEETINGSTONE_LEAVE = 0x293,
            CMSG_MEETINGSTONE_CHEAT = 0x294,
            SMSG_MEETINGSTONE_SETQUEUE = 0x295,
            CMSG_MEETINGSTONE_INFO = 0x296,
            SMSG_MEETINGSTONE_COMPLETE = 0x297,
            SMSG_MEETINGSTONE_IN_PROGRESS = 0x298,
            SMSG_MEETINGSTONE_MEMBER_ADDED = 0x299,
            CMSG_GMTICKETSYSTEM_TOGGLE = 0x29A,
            CMSG_CANCEL_GROWTH_AURA = 0x29B,
            SMSG_CANCEL_AUTO_REPEAT = 0x29C,
            SMSG_STANDSTATE_UPDATE = 0x29D,
            SMSG_LOOT_ALL_PASSED = 0x29E,
            SMSG_LOOT_ROLL_WON = 0x29F,
            CMSG_LOOT_ROLL = 0x2A0,
            SMSG_LOOT_START_ROLL = 0x2A1,
            SMSG_LOOT_ROLL = 0x2A2,
            CMSG_LOOT_MASTER_GIVE = 0x2A3,
            SMSG_LOOT_MASTER_LIST = 0x2A4,
            SMSG_SET_FORCED_REACTIONS = 0x2A5,
            SMSG_SPELL_FAILED_OTHER = 0x2A6,
            SMSG_GAMEOBJECT_RESET_STATE = 0x2A7,
            CMSG_REPAIR_ITEM = 0x2A8,
            SMSG_CHAT_PLAYER_NOT_FOUND = 0x2A9,
            MSG_TALENT_WIPE_CONFIRM = 0x2AA,
            SMSG_SUMMON_REQUEST = 0x2AB,
            CMSG_SUMMON_RESPONSE = 0x2AC,
            MSG_MOVE_TOGGLE_GRAVITY_CHEAT = 0x2AD,
            SMSG_MONSTER_MOVE_TRANSPORT = 0x2AE,
            SMSG_PET_BROKEN = 0x2AF,
            MSG_MOVE_FEATHER_FALL = 0x2B0,
            MSG_MOVE_WATER_WALK = 0x2B1,
            CMSG_SERVER_BROADCAST = 0x2B2,
            CMSG_SELF_RES = 0x2B3,
            SMSG_FEIGN_DEATH_RESISTED = 0x2B4,
            CMSG_RUN_SCRIPT = 0x2B5,
            SMSG_SCRIPT_MESSAGE = 0x2B6,
            SMSG_DUEL_COUNTDOWN = 0x2B7,
            SMSG_AREA_TRIGGER_MESSAGE = 0x2B8,
            CMSG_TOGGLE_HELM = 0x2B9,
            CMSG_TOGGLE_CLOAK = 0x2BA,
            SMSG_MEETINGSTONE_JOINFAILED = 0x2BB,
            SMSG_PLAYER_SKINNED = 0x2BC,
            SMSG_DURABILITY_DAMAGE_DEATH = 0x2BD,
            CMSG_SET_EXPLORATION = 0x2BE,
            CMSG_SET_ACTIONBAR_TOGGLES = 0x2BF,
            MSG_DELETE_GUILD_CHARTER = 0x2C0,
            MSG_PETITION_RENAME = 0x2C1,
            SMSG_INIT_WORLD_STATES = 0x2C2,
            SMSG_UPDATE_WORLD_STATE = 0x2C3,
            CMSG_ITEM_NAME_QUERY = 0x2C4,
            SMSG_ITEM_NAME_QUERY_RESPONSE = 0x2C5,
            SMSG_PET_ACTION_FEEDBACK = 0x2C6,
            CMSG_CHAR_RENAME = 0x2C7,
            SMSG_CHAR_RENAME = 0x2C8,
            CMSG_MOVE_SPLINE_DONE = 0x2C9,
            CMSG_MOVE_FALL_RESET = 0x2CA,
            SMSG_INSTANCE_SAVE_CREATED = 0x2CB,
            SMSG_RAID_INSTANCE_INFO = 0x2CC,
            CMSG_REQUEST_RAID_INFO = 0x2CD,
            CMSG_MOVE_TIME_SKIPPED = 0x2CE,
            CMSG_MOVE_FEATHER_FALL_ACK = 0x2CF,
            CMSG_MOVE_WATER_WALK_ACK = 0x2D0,
            CMSG_MOVE_NOT_ACTIVE_MOVER = 0x2D1,
            SMSG_PLAY_SOUND = 0x2D2,
            CMSG_BATTLEFIELD_STATUS = 0x2D3,
            SMSG_BATTLEFIELD_STATUS = 0x2D4,
            CMSG_BATTLEFIELD_PORT = 0x2D5,
            MSG_INSPECT_HONOR_STATS = 0x2D6,
            CMSG_BATTLEMASTER_HELLO = 0x2D7,
            CMSG_MOVE_START_SWIM_CHEAT = 0x2D8,
            CMSG_MOVE_STOP_SWIM_CHEAT = 0x2D9,
            SMSG_FORCE_WALK_SPEED_CHANGE = 0x2DA,
            CMSG_FORCE_WALK_SPEED_CHANGE_ACK = 0x2DB,
            SMSG_FORCE_SWIM_BACK_SPEED_CHANGE = 0x2DC,
            CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK = 0x2DD,
            SMSG_FORCE_TURN_RATE_CHANGE = 0x2DE,
            CMSG_FORCE_TURN_RATE_CHANGE_ACK = 0x2DF,
            MSG_PVP_LOG_DATA = 0x2E0,
            CMSG_LEAVE_BATTLEFIELD = 0x2E1,
            CMSG_AREA_SPIRIT_HEALER_QUERY = 0x2E2,
            CMSG_AREA_SPIRIT_HEALER_QUEUE = 0x2E3,
            SMSG_AREA_SPIRIT_HEALER_TIME = 0x2E4,
            CMSG_GM_UNTEACH = 0x2E5,
            SMSG_WARDEN_DATA = 0x2E6,
            CMSG_WARDEN_DATA = 0x2E7,
            SMSG_GROUP_JOINED_BATTLEGROUND = 0x2E8,
            MSG_BATTLEGROUND_PLAYER_POSITIONS = 0x2E9,
            CMSG_PET_STOP_ATTACK = 0x2EA,
            SMSG_BINDER_CONFIRM = 0x2EB,
            SMSG_BATTLEGROUND_PLAYER_JOINED = 0x2EC,
            SMSG_BATTLEGROUND_PLAYER_LEFT = 0x2ED,
            CMSG_BATTLEMASTER_JOIN = 0x2EE,
            SMSG_ADDON_INFO = 0x2EF,
            CMSG_PET_UNLEARN = 0x2F0,
            SMSG_PET_UNLEARN_CONFIRM = 0x2F1,
            SMSG_PARTY_MEMBER_STATS_FULL = 0x2F2,
            CMSG_PET_SPELL_AUTOCAST = 0x2F3,
            SMSG_WEATHER = 0x2F4,
            SMSG_PLAY_TIME_WARNING = 0x2F5,
            SMSG_MINIGAME_SETUP = 0x2F6,
            SMSG_MINIGAME_STATE = 0x2F7,
            CMSG_MINIGAME_MOVE = 0x2F8,
            SMSG_MINIGAME_MOVE_FAILED = 0x2F9,
            SMSG_RAID_INSTANCE_MESSAGE = 0x2FA,
            SMSG_COMPRESSED_MOVES = 0x2FB,
            CMSG_GUILD_INFO_TEXT = 0x2FC,
            SMSG_CHAT_RESTRICTED = 0x2FD,
            SMSG_SPLINE_SET_RUN_SPEED = 0x2FE,
            SMSG_SPLINE_SET_RUN_BACK_SPEED = 0x2FF,
            SMSG_SPLINE_SET_SWIM_SPEED = 0x300,
            SMSG_SPLINE_SET_WALK_SPEED = 0x301,
            SMSG_SPLINE_SET_SWIM_BACK_SPEED = 0x302,
            SMSG_SPLINE_SET_TURN_RATE = 0x303,
            SMSG_SPLINE_MOVE_UNROOT = 0x304,
            SMSG_SPLINE_MOVE_FEATHER_FALL = 0x305,
            SMSG_SPLINE_MOVE_NORMAL_FALL = 0x306,
            SMSG_SPLINE_MOVE_SET_HOVER = 0x307,
            SMSG_SPLINE_MOVE_UNSET_HOVER = 0x308,
            SMSG_SPLINE_MOVE_WATER_WALK = 0x309,
            SMSG_SPLINE_MOVE_LAND_WALK = 0x30A,
            SMSG_SPLINE_MOVE_START_SWIM = 0x30B,
            SMSG_SPLINE_MOVE_STOP_SWIM = 0x30C,
            SMSG_SPLINE_MOVE_SET_RUN_MODE = 0x30D,
            SMSG_SPLINE_MOVE_SET_WALK_MODE = 0x30E,
            CMSG_GM_NUKE_ACCOUNT = 0x30F,
            MSG_GM_DESTROY_CORPSE = 0x310,
            CMSG_GM_DESTROY_ONLINE_CORPSE = 0x311,
            CMSG_ACTIVATETAXIEXPRESS = 0x312,
            SMSG_SET_FACTION_ATWAR = 0x313,
            SMSG_GAMETIMEBIAS_SET = 0x314,
            CMSG_DEBUG_ACTIONS_START = 0x315,
            CMSG_DEBUG_ACTIONS_STOP = 0x316,
            CMSG_SET_FACTION_INACTIVE = 0x317,
            CMSG_SET_WATCHED_FACTION = 0x318,
            MSG_MOVE_TIME_SKIPPED = 0x319,
            SMSG_SPLINE_MOVE_ROOT = 0x31A,
            CMSG_SET_EXPLORATION_ALL = 0x31B,
            SMSG_INVALIDATE_PLAYER = 0x31C,
            CMSG_RESET_INSTANCES = 0x31D,
            SMSG_INSTANCE_RESET = 0x31E,
            SMSG_INSTANCE_RESET_FAILED = 0x31F,
            SMSG_UPDATE_LAST_INSTANCE = 0x320,
            MSG_RAID_TARGET_UPDATE = 0x321,
            MSG_RAID_READY_CHECK = 0x322,
            CMSG_LUA_USAGE = 0x323,
            SMSG_PET_ACTION_SOUND = 0x324,
            SMSG_PET_DISMISS_SOUND = 0x325,
            SMSG_GHOSTEE_GONE = 0x326,
            CMSG_GM_UPDATE_TICKET_STATUS = 0x327,
            SMSG_GM_TICKET_STATUS_UPDATE = 0x328,
            CMSG_GMSURVEY_SUBMIT = 0x32A,
            SMSG_UPDATE_INSTANCE_OWNERSHIP = 0x32B,
            CMSG_IGNORE_KNOCKBACK_CHEAT = 0x32C,
            SMSG_CHAT_PLAYER_AMBIGUOUS = 0x32D,
            MSG_DELAY_GHOST_TELEPORT = 0x32E,
            SMSG_SPELLINSTAKILLLOG = 0x32F,
            SMSG_SPELL_UPDATE_CHAIN_TARGETS = 0x330,
            CMSG_CHAT_FILTERED = 0x331,
            SMSG_EXPECTED_SPAM_RECORDS = 0x332,
            SMSG_SPELLSTEALLOG = 0x333,
            CMSG_LOTTERY_QUERY_OBSOLETE = 0x334,
            SMSG_LOTTERY_QUERY_RESULT_OBSOLETE = 0x335,
            CMSG_BUY_LOTTERY_TICKET_OBSOLETE = 0x336,
            SMSG_LOTTERY_RESULT_OBSOLETE = 0x337,
            SMSG_CHARACTER_PROFILE = 0x338,
            SMSG_CHARACTER_PROFILE_REALM_CONNECTED = 0x339,
            SMSG_DEFENSE_MESSAGE = 0x33B,
            NUM_MSG_TYPES = 0x33C
    };
    return r;
    }

public:
    static bool IsUserFriendlyLogEnabled()
    {
        return _userFiendlyLogStatus == USER_FRIENDLY_LOG_ENABLED;
    }

    // just this method should be used "globally"
    // basically logs the packets via other private functions
    static void DumpPacket(const char* userFriendlyDumpFileName,
                           const char* binaryDumpFileName,
                           PacketType packetType,
                           DWORD packetOpcode,
                           DWORD packetSize,
                           DWORD buffer,
                           WORD initialReadOffset)
    {
        // gets the time
        time_t rawTime;
        time(&rawTime);

        // only dumps "user friendly" format if
        // "dump_user_friendly" file exists
        if (_userFiendlyLogStatus == USER_FRIENDLY_LOG_NOT_CHECKED)
        {
            if (PathFileExists(enableUserFriendlyPath))
                _userFiendlyLogStatus = USER_FRIENDLY_LOG_ENABLED;
            else
                _userFiendlyLogStatus = USER_FRIENDLY_LOG_DISABLED;
        }

        if (IsUserFriendlyLogEnabled())
        {
            if (!userFriendlyDumpFile)
            {
                userFriendlyDumpFile = fopen(userFriendlyDumpFileName, "w");
                if (!userFriendlyDumpFile)
                {
                    printf("Cannot open file: %s, error code: %d - %s",
                           userFriendlyDumpFileName, errno, strerror(errno));
                    return;
                }
            }

            // dumps the "user friendly" format of the packet
            DumpPacketUserFriendly(userFriendlyDumpFile,
                                   packetType,
                                   packetOpcode,
                                   packetSize,
                                   buffer,
                                   rawTime,
                                   initialReadOffset);
            fflush(userFriendlyDumpFile);
        }

        if (!binaryDumpFile)
        {
            binaryDumpFile = fopen(binaryDumpFileName, "wb"); // binary mode
            if (!binaryDumpFile)
            {
                printf("Cannot open file: %s, error code: %d - %s",
                       binaryDumpFileName, errno, strerror(errno));
                return;
            }
        }
        // dumps the binary format of the packet
        DumpPacketBinary(binaryDumpFile,
                         packetType,
                         packetOpcode,
                         packetSize,
                         buffer,
                         rawTime,
                         initialReadOffset);
        fflush(binaryDumpFile);
    }

private:
    static void DumpPacketUserFriendly(FILE* file, PacketType packetType, DWORD packetOpcode, DWORD packetSize, DWORD buffer, time_t timestamp, WORD initialReadOffset)
    {

        // writes a header and a ruler
        WriteUserFriendlyHeader(file, packetType, packetOpcode, packetSize, timestamp);
        WriteUserFriendlyRuler(file);

        // really dumps the packet's data
        WriteUserFriendlyPacketDump(file, packetType, buffer, packetSize, initialReadOffset);

        // ruler again
        WriteUserFriendlyRuler(file);
        fprintf(file, "\n\n");
    }

    // a header which contains some details about the packet
    // packet direction, opcode, size, timestamp, date
    static void WriteUserFriendlyHeader(FILE* file, PacketType packetType, DWORD packetOpcode, DWORD packetSize, time_t timestamp)
    {
        // packet direction string
        char* packetTypeString = "";
        if (packetType == PACKET_TYPE_C2S)
            packetTypeString = "CMSG";
        else
            packetTypeString = "SMSG";

        packetTypeString = getopcodename(packetOpcode);

        tm* date = localtime(&timestamp);
        // date format
        char dateStr[32];
        // fills the date, format: YYYY. mm. dd. - HH:ii:ss
        _snprintf(dateStr,
                  32,
                  "%d. %02d. %02d. - %02d:%02d:%02d",
                  date->tm_year + 1900,
                  date->tm_mon + 1,
                  date->tm_mday,
                  date->tm_hour,
                  date->tm_min,
                  date->tm_sec);

        // the 2 rows header
        fprintf(file,
                "Packet type: %s, Opcode: 0x%04X, Packet size: %u bytes\n"
                "Timestamp: %u, Date: %s\n",
                packetTypeString,
                packetOpcode,
                packetSize,
                (DWORD)timestamp,
                dateStr);
    }

    // a "ruler" which makes easier to read the "user friendly" dump
    static void WriteUserFriendlyRuler(FILE* file)
    {
        char* ruler =
        "|--------|-------------------------------------------------|---------------------------------|\n"
        "|        | 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F | 0 1 2 3 4 5 6 7 8 9 A B C D E F |\n"
        "|--------|-------------------------------------------------|---------------------------------|\n";
        fprintf(file, ruler);
    }

    // the real work of the "user friendly" packet
    static void WriteUserFriendlyPacketDump(FILE* file, PacketType packetType, DWORD buffer, DWORD packetSize, WORD initialReadOffset)
    {
        // empty packet
        if (packetSize == 0)
        {
            fprintf(file, "|        |                   EMPTY PACKET                  |           EMPTY PACKET          |\n");
            return;
        }

        // some magic to get the proper, nice format
        // should be hard to comment that... :)
        DWORD readOffset1 = initialReadOffset;
        DWORD readOffset2 = initialReadOffset;
        for (DWORD i = 0; i < packetSize; ++i)
        {
            if (i % 0x10 != 0)
                continue;
            fprintf(file, "| 0x%04X | ", i + 1);
            for (DWORD j = 0; j < 0x10; ++j)
            {
                if ((i + j) > packetSize - 1)
                    break;
                BYTE byte = *(BYTE*)(buffer + readOffset1++);
                fprintf(file, "%02X ", byte);
            }
            if (i + 0x0F > packetSize - 1)
                for (DWORD j = 0; j < i + 0x10 - packetSize; ++j)
                    fprintf(file, "%s", "   ");
            fprintf(file, "%s ", "|");
            for (DWORD j = 0; j < 0x10; ++j)
            {
                if ((i + j) > packetSize - 1)
                    break;
                BYTE byte = *(BYTE*)(buffer + readOffset2++);
                if (byte >= 0x20 && byte < 0x7F)
                    fprintf(file, "%c ", (char)byte);
                else
                    fprintf(file, "%s ", ".");
            }
            if (i + 0x0F > packetSize - 1)
                for (DWORD j = 0; j < i + 0x10 - packetSize; ++j)
                    fprintf(file, "%s", "  ");
            fprintf(file, "%s\n", "|");
        }
    }

    // saves the packet in Trinity's WPP format
    // https://github.com/TrinityCore/WowPacketParser
    static void DumpPacketBinary(FILE* file,
                                 PacketType packetType,
                                 DWORD packetOpcode,
                                 DWORD packetSize,
                                 DWORD buffer,
                                 time_t timestamp,
                                 WORD initialReadOffset)
    {
        fwrite(&packetOpcode,       4, 1, file); // opcode
        fwrite(&packetSize,         4, 1, file); // size of the packet
        fwrite((DWORD*)&timestamp,  4, 1, file); // timestamp of the packet
        fwrite((BYTE*)&packetType,  1, 1, file); // direction of the packet

        // loops over the packet and saves the data
        for (DWORD i = 0; i < packetSize; ++i)
        {
            BYTE byte = *(BYTE*)(buffer + initialReadOffset + i);
            fwrite(&byte, 1, 1, file);
        }
    }
};
