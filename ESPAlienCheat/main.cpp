#include "overlay.h"
#include "memory.h"
#include "utility.h"
#include "struct.h"
#include "protect/protectmain.h"

#include "auth.hpp"

ImColor cRainbow;

using namespace KeyAuth;

std::string namee = _xor_("Rust Private"); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = _xor_("jHHXUBClti"); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = _xor_("7fc52ddfed40f4f1a9ba1eb0902aca2e35869a425afa2abb2f625342fd02a38a"); // app secret, the blurred text on licenses tab and other tabs
std::string version = _xor_("1.1"); // leave alone unless you've changed version on website
std::string url = _xor_("https://auth.aliencheats.com/api/1.1/"); // change if you're self-hosting
std::string sslPin = _xor_("ssl pin key (optional)"); // don't change unless you intend to pin public certificate key. you can get here in the "Pin SHA256" field https://www.ssllabs.com/ssltest/analyze.html?d=keyauth.win&latest. If you do this you need to be aware of when SSL key expires so you can update it
api KeyAuthApp(namee, ownerid, secret, version, url, sslPin);


static int xekran = 576, yekran = 386;
static int sayfa = 1;


static int MenuSayfasi = 6;
bool cross = false;
bool ADS_Hide = false;
bool Giris = true;

inline bool enable = false;
inline bool esp = false;
inline bool espon = false;

inline float timee = 12;
inline float light = 1;
inline float gravity_distancee = 5;
static bool bok = false;

inline bool hepsi = true;
static bool hidescript1 = true;
static bool hidescript2 = true;
static bool hidescript3 = true;
static bool hidescript4 = true;
inline bool admin_flag_checkboxx = false;
inline bool hardcoremodeMap = false;
inline bool spiderman = false;
inline bool norecoil = false;
inline bool hanging = false;
inline bool thirdperson = false;
inline bool gravity = false;
inline bool fatbullet = false;
inline bool nospread = false;
inline bool alwaysday = false;
inline bool alwaysdaytog = true;
inline bool fovtamiri = false;
inline bool nightmodetamiri = false;
inline bool fakeworkbench = false;
inline bool Spectating = false;
inline bool fov = false;
inline bool WalkOnWater = false;
inline bool flyhack = false;
inline bool climb = false;
inline bool infinitejump = false;
inline bool nospread_checkbox = false;
inline bool fat_bullet_checkbox = false;
inline bool super_eoka_checkbox = false;
inline bool full_automatic_checkbox = false;
inline bool jumpshot = false;
inline bool aydinlik = false;
inline bool fastswim = false;
inline bool fastswimm = false;
inline bool SPEEDhack = false;
inline bool change_time_checkbox = false;
inline bool zoom = false;
inline bool suicide = false;
inline bool AdminEsp = false;
inline bool nighttmode = false;
inline bool cullingtamiri = false;
inline bool fatbullettamiri = false;
inline bool eokatamiri = false;
inline bool ototamiri = false;
inline bool instantCompound = false;
inline bool instabow = false;
inline bool fakelag = false;
inline bool nosway = false;
inline bool supermeele = false;
inline bool fastswitch = false;
inline bool meeletamiri = false;
inline bool noshotgunspread = false;
inline bool longneck = false;
inline bool cameraaa = false;
inline bool timer = false;
inline bool chams = false;
inline bool chamstamiri = false;
inline bool spinbot = false;

static int WalkOnWaterr = 0x5A;
static int FlyHackButon = 0x46;
static int hangingg = VK_XBUTTON2;
static int speedbutton = VK_XBUTTON1;
static int zoombutton = 0;
static int climbbutton = 0x58;



float FOVV = 120.f;
float speedBonus = 0.5f;
float flyhackspeed = 0.f;
float zoomyer = 42.f;
float timervalue = 2.f;

float NeckWidgth = 0.f;
float NeckLength = 0.f;
float NeckWeigth = 0.f;

bool control = false;


std::wstring get_item_name(uintptr_t item)
{
	auto unk = driver.read<UINT64>(item + 0x20);
	unk = driver.read<UINT64>(unk + 0x20);
	return driver.read_wstring(unk + 0x14, 14);
}
bool is_weapon(uintptr_t helditem)
{
	auto ItemName = get_item_name(helditem);
	if (ItemName.find(L"rifle") != std::string::npos) return true;
	if (ItemName.find(L"pistol") != std::string::npos) return true;
	if (ItemName.find(L"bow.hunting") != std::string::npos) return true;
	if (ItemName.find(L"bow") != std::string::npos) return true;
	if (ItemName.find(L"lmg") != std::string::npos) return true;
	if (ItemName.find(L"shotgun") != std::string::npos) return true;
	if (ItemName.find(L"smg") != std::string::npos) return true;
	else return false;
}

bool is_meele(uintptr_t helditem)
{
	auto ItemName = get_item_name(helditem);
	if (ItemName.find(L"rock") != std::string::npos) return true;
	if (ItemName.find(L"hatchet") != std::string::npos) return true;
	if (ItemName.find(L"stone.pickaxe") != std::string::npos) return true;
	if (ItemName.find(L"stonehatchet") != std::string::npos) return true;
	if (ItemName.find(L"pickaxe") != std::string::npos) return true;
	if (ItemName.find(L"hammer.salvage") != std::string::npos) return true;
	if (ItemName.find(L"icepick.salvag") != std::string::npos) return true;
	if (ItemName.find(L"axe.salvaged") != std::string::npos) return true;
	if (ItemName.find(L"pitchfork") != std::string::npos) return true;
	if (ItemName.find(L"mace") != std::string::npos) return true;
	if (ItemName.find(L"spear.stone") != std::string::npos) return true;
	if (ItemName.find(L"spear.wooden") != std::string::npos) return true;
	if (ItemName.find(L"machete") != std::string::npos) return true;
	if (ItemName.find(L"bone.club") != std::string::npos) return true;
	if (ItemName.find(L"paddle") != std::string::npos) return true;
	if (ItemName.find(L"salvaged.sword") != std::string::npos) return true;
	if (ItemName.find(L"salvaged.cleav") != std::string::npos) return true;
	if (ItemName.find(L"knife.combat") != std::string::npos) return true;
	if (ItemName.find(L"knife.butcher") != std::string::npos) return true;
	if (ItemName.find(L"jackhammer") != std::string::npos) return true;
	if (ItemName.find(L"chainsaw") != std::string::npos) return true;
	if (ItemName.find(L"knife.bone") != std::string::npos) return true;
	if (ItemName.find(L"torch") != std::string::npos) return true;
	if (ItemName.find(L"hammer") != std::string::npos) return true;
	if (ItemName.find(L"sickle") != std::string::npos) return true;
	else return false;
}
void omni()
{
	while (true)
	{
		auto baseMove = driver.read<uintptr_t>(Local_Player + oPlayerMovement); //baseplayer -> basemovement
		driver.write<float>(baseMove + 0x40, 5.f);
	}
}

unsigned short lfsr = 0xACE1u;
unsigned int bit = 0;

unsigned RANDOMVECTOR()
{
	if (!lfsr) {
		lfsr = 0xACE1u; bit = 0;
	}
	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
	return lfsr = (lfsr >> 1) | (bit << 15);
}



bool moon = true;

Vector3 multiplyQuad(Vector4 quat, Vector3 vec)
{
	float num = quat.x * 2.f;
	float num2 = quat.y * 2.f;
	float num3 = quat.z * 2.f;
	float num4 = quat.x * num;
	float num5 = quat.y * num2;
	float num6 = quat.z * num3;
	float num7 = quat.x * num2;
	float num8 = quat.x * num3;
	float num9 = quat.y * num3;
	float num10 = quat.w * num;
	float num11 = quat.w * num2;
	float num12 = quat.w * num3;
    Vector3 result;
	result.x = (1.f - (num5 + num6)) * vec.x + (num7 - num12) * vec.y + (num8 + num11) * vec.z;
	result.y = (num7 + num12) * vec.x + (1.f - (num4 + num6)) * vec.y + (num9 - num10) * vec.z;
	result.z = (num8 - num11) * vec.x + (num9 + num10) * vec.y + (1.f - (num4 + num5)) * vec.z;
	return result;
}

void Hilee()
{
	while (true)
	{

		/*	auto main_offsets = driver.read<uintptr_t>(g_assembly + BaseGameMode);
			Local_Player = driver.read_chain(main_offsets, { 0xb8, 0x20, 0x10, 0x28, 0x18, 0x20 });*/
			/// 

		int flag = driver.read<int>(Local_Player + playerflags);
		auto Movement = driver.read<uintptr_t>(Local_Player + oPlayerMovement);

		const auto current_item = GetHeldItem(Local_Player);
		auto base_projectile = driver.read<uintptr_t>(current_item + oHeld);
		auto recoil_prop = driver.read<uintptr_t>(base_projectile + oRecoilProperties);
		auto newRecoilOverride = driver.read<uintptr_t>(recoil_prop + 0x78);




		//uintptr_t BaseGameMode = driver.read<uintptr_t>(g_assembly + BaseGameMode);
		//uintptr_t h1 = driver.read<uintptr_t>(BaseGameMode + 0xB8);
		//uintptr_t h2 = driver.read<uintptr_t>(h1 + 0x20);
		//uintptr_t h3 = driver.read<uintptr_t>(h2 + 0x10);
		//uintptr_t h4 = driver.read<uintptr_t>(h3 + 0x28);
		//objectList = driver.read<uintptr_t>(h4 + 0x18);
		//objectListSize = driver.read<uint32_t>(h4 + 0x10);
		//if (!objectListSize)
		//	return;


		//	



		if (hardcoremodeMap)
		{
			auto HardCoreMap = driver.read<uintptr_t>(g_assembly + BaseGameMode2); //       "Signature": "BaseGameMode_c*"	
			auto HardCoreMapOn = driver.read_chain(HardCoreMap, { 0xb8, 0x8 });
			driver.write<bool>(HardCoreMapOn + 0x17C, true); // public bool ingameMap;
			driver.write<bool>(HardCoreMapOn + 0x17D, true); // public bool compass;
		}

		if (admin_flag_checkboxx == true) { // adminmode ve debugcamera repair
			

			if (driver.read<uintptr_t>(Local_Player + playerflags) != 4) {
				driver.write<uintptr_t>(Local_Player + playerflags, 4);
			}

			auto klass = driver.read<uintptr_t>(g_assembly + ConVar_Client_c);
			auto static_fields = driver.read<uintptr_t>(klass + 0xB8);
			driver.write<float>(static_fields + oCamSpeed, 1.f);
			driver.write<float>(static_fields + oCamLerp, 1.f);

			driver.write<bool>(Movement + 0x18, false); // noclipi oto kapatýyor

			auto ConsoleSystemCommands15 = driver.read<uintptr_t>(g_assembly + ConsoleSystem_Index_c); // "Signature": "ConsoleSystem_Index_c*"
			auto ConsoleSystemCommands16 = driver.read_chain(ConsoleSystemCommands15, { 0xb8 });
			uintptr_t ConsoleSystemCommands = driver.read<uintptr_t>(ConsoleSystemCommands16 + 0x10);
			if (!ConsoleSystemCommands) return;

			for (int x = 0; x < 500; x++)
			{
				uintptr_t ConsoleSystemCommand = driver.read<uintptr_t>(ConsoleSystemCommands + 0x20 + (x * 0x8));
				if (!ConsoleSystemCommand) continue;

				uintptr_t Name = driver.read<uintptr_t>(ConsoleSystemCommand + 0x10);
				if (!Name) continue;

				wchar_t command_name[36] = { '\0' };
				driver.read_array(Name + 0x14, command_name, sizeof(command_name));

				if (!wcscmp(command_name, L"debugcamera"))
				{
					driver.write<bool>(0, ConsoleSystemCommand + 0x57);
				}
			}

		}
		if (thirdperson == true)
		{
			if (driver.read<uintptr_t>(Local_Player + playerflags) != 1024) {
				driver.write<uintptr_t>(Local_Player + playerflags, 1024);
			}
		}
		if (AdminEsp == true)
		{
			if (cullingtamiri)
			{
				auto OcclusionCulling = driver.read<uintptr_t>(g_assembly + 52894448); //       "Signature": "OcclusionCulling_c*"
				auto CullingDebugOnOff = driver.read<uintptr_t>(OcclusionCulling + 0xB8);
				auto OcclusionCullingEditted = driver.read_chain(OcclusionCulling, { 0xB8, 128, 0x18 });
				driver.write<uintptr_t>(OcclusionCullingEditted + 0x20, 131072);
				if (driver.read<uintptr_t>(CullingDebugOnOff + 0x94) != 1) {
					driver.write<uintptr_t>(CullingDebugOnOff + 0x94, 1);
				}
				cullingtamiri = false;
			}
		}
		else
		{
			if (!cullingtamiri)
			{
				auto OcclusionCulling = driver.read<uintptr_t>(g_assembly + 52894448); //       "Signature": "OcclusionCulling_c*"
				auto CullingDebugOnOff = driver.read<uintptr_t>(OcclusionCulling + 0xB8);
				if (driver.read<uintptr_t>(CullingDebugOnOff + 0x94) != 0) {
					driver.write<uintptr_t>(CullingDebugOnOff + 0x94, 0);
				}
				cullingtamiri = true;
			}
		}
		auto klass2 = driver.read<uintptr_t>(g_assembly + ConVar_Admin_c); // convar_admin_c*
		auto static_fields2 = driver.read<uintptr_t>(klass2 + 0xb8);
		if (nighttmode)
		{
			driver.write<float>(static_fields2 + 0x0, 7);  // public static float admintime;
			driver.write<float>(static_fields2 + 0x4, 0);  // public static float adminlight;
			driver.write<float>(static_fields2 + 0x8, 16); // public static float adminreflectionmultiplier;
		}
		else
		{
			driver.write<float>(static_fields2 + 0x0, -1); // public static float admintime;
			driver.write<float>(static_fields2 + 0x4, -1); // public static float adminlight;
			driver.write<float>(static_fields2 + 0x8, 0);  // public static float adminreflectionmultiplier;
		}
		if (alwaysday)
		{
			alwaysdaytog = false;
			if (driver.read<float>(static_fields2 + 0x0) != timee) {
				driver.write<float>(static_fields2 + 0x0, timee); // public static float admintime;
			}
			if (driver.read<float>(static_fields2 + 0x4) != light) {
				driver.write<float>(static_fields2 + 0x4, light); // public static float admintime;
			}
		}
		else
		{
			if (!alwaysdaytog)
			{
				if (driver.read<float>(static_fields2 + 0x0) != -1) {
					driver.write<float>(static_fields2 + 0x0, -1); // public static float admintime;
				}
				if (driver.read<float>(static_fields2 + 0x4) != -1) {
					driver.write<float>(static_fields2 + 0x4, -1); // public static float admintime;
				}
				alwaysdaytog = true;
			}
		}
		if (spiderman == true) {
			if (driver.read<float>(Movement + groundAngle) != 0.f) {
				driver.write<float>(Movement + groundAngle, 0.f);
			}
			if (driver.read<float>(Movement + groundAngleNew) != 0.f) {
				driver.write<float>(Movement + groundAngleNew, 0.f);
			}
		}
		if (infinitejump == true) {
			if (GetAsyncKeyState(VK_SPACE))
			{
				driver.write<Vector3>(Movement + 0xc8, Vector3(0, 10000000, 0));
				driver.write<Vector3>(Movement + 0xc4, Vector3(99999999, 99999999, 99999999));
			}
		}
		if (suicide == true)
		{
			if (GetAsyncKeyState(VK_END))
			{
				driver.write<bool>(Movement + wasFalling, true);
				driver.write<Vector3>(Movement + previousVelocity, Vector3(0, -20, 0));
				driver.write<float>(Movement + groundTime, 0.f);
			}
		}
		if (gravity == true) {
			if (GetAsyncKeyState(VK_SPACE))
			{
				if (driver.read<float>(Movement + oGravityMultiplier) != gravity_distancee / 2) {
					driver.write<float>(Movement + oGravityMultiplier, gravity_distancee / 2);
				}
			}
		}
		if (fakeworkbench == true) {
			if (driver.read<int>(Local_Player + playerflags) != (flag |= 4194304)) {
				driver.write<int>(Local_Player + playerflags, (flag |= 4194304));
			}
		}
		if (WalkOnWater == true) {
			if (GetAsyncKeyState(WalkOnWaterr))
			{
				if (driver.read<float>(Movement + groundAngle) != 0.f) {
					driver.write<float>(Movement + groundAngle, 0.f);//groundAngle
					driver.write<float>(Movement + groundAngleNew, 0.f);//groundAngleNew
					driver.write<float>(Movement + oGravityMultiplier, 0.f);//gravityMultiplier
				}
			}
			else
			{
				if (driver.read<float>(Movement + oGravityMultiplier) != 2.5f) {
					driver.write<float>(Movement + oGravityMultiplier, 2.5f);//gravityMultiplier
				}
			}
		}
		if (flyhack == true) {
			if (GetAsyncKeyState(FlyHackButon))
			{

				driver.write<float>(Movement + groundAngle, flyhackspeed);//groundAngle
				driver.write<float>(Movement + groundAngleNew, flyhackspeed);//groundAngleNew
				driver.write<float>(Movement + oGravityMultiplier, flyhackspeed);//gravityMultiplier

			}
			else
			{
				if (driver.read<float>(Movement + oGravityMultiplier) != 2.5f) {
					driver.write<float>(Movement + oGravityMultiplier, 2.5f);//gravityMultiplier
				}
			}
		}
		if (climb == TRUE)
		{
			if (GetAsyncKeyState(climbbutton))
			{

				driver.write<float>(Movement + capsuleHeight, -100);
				driver.write<float>(Movement + capsuleCenter, -100);
			}
			else
			{
				if (driver.read<float>(Movement + capsuleHeight) != 1.79f) {
					driver.write<float>(Movement + capsuleHeight, 1.79f);
					driver.write<float>(Movement + capsuleCenter, 0.899f);
				}
			}
		}
		if (fov == TRUE) {
			uint64_t fov = driver.read<UINT64>(g_assembly + oFovConVarGraphics); // "Signature": "ConVar_Graphics_c"
			uint64_t instance = driver.read<UINT64>(fov + 0xB8);
			if (driver.read<float>(instance + 0X18) != FOVV) {
				driver.write<float>(instance + 0X18, FOVV); // public static float admintime;
			}
			alwaysdaytog = false;
		}
		if (!fov == TRUE)
		{
			if (!fovtamiri)
			{
				uint64_t fov = driver.read<UINT64>(g_assembly + oFovConVarGraphics); // "Signature": "ConVar_Graphics_c"
				uint64_t instance = driver.read<UINT64>(fov + 0xB8);
				if (driver.read<float>(instance + 0X18) != 90) {
					driver.write<float>(instance + 0X18, 90); // public static float admintime;
				}
				alwaysdaytog = true;
			}
		}
		if (jumpshot == TRUE) {
			auto mov_flag = driver.read<uintptr_t>(Movement + oModelState);
			driver.write<uintptr_t>(mov_flag, oFlagOnGround);
			driver.write<float>(Movement + groundAngle, 1.f);
			driver.write<float>(Movement + groundAngleNew, 1.f);
		}
		if (zoom == TRUE)
		{
			if (GetAsyncKeyState(VK_RBUTTON))
			{
				uint64_t fov = driver.read<UINT64>(g_assembly + oFovConVarGraphics); // "Signature": "ConVar_Graphics_c" // DONE
				uint64_t instance = driver.read<UINT64>(fov + 0xB8);
				if (driver.read<float>(instance + 0X18) != zoomyer) {
					driver.write<float>(instance + 0X18, zoomyer); // public static float admintime;
				}
			}
		}
		if (fastswim == TRUE)
		{
			if (driver.read<float>(Local_Player + oclothingWaterSpeedBonus) != 0.2f) {
				driver.write<float>(Local_Player + oclothingWaterSpeedBonus, 0.2f); // public static float admintime;
			}
			fastswimm == false;
		}
		if (!fastswim == TRUE)
		{
			if (!fastswimm)
			{
				if (driver.read<float>(Local_Player + oclothingWaterSpeedBonus) != 0.1) {
					driver.write<float>(Local_Player + oclothingWaterSpeedBonus, 0.1); // public static float admintime;
				}
				fastswimm == true;
			}
		}
		if (SPEEDhack == TRUE)
		{
			if (GetAsyncKeyState(speedbutton))
			{
				driver.write<float>(Local_Player + clothingMoveSpeedReduction, 0.f - speedBonus); // public static float admintime;
			}
			if (!GetAsyncKeyState(speedbutton))
			{
				driver.write<float>(Local_Player + clothingMoveSpeedReduction, 0.f - 0.f); // public static float admintime;
			}
		}
		if (cameraaa)
		{
			auto eyes = driver.read<uintptr_t>(Local_Player + oPlayerEyes);
			driver.write<Vector3>(eyes + 0x38, Vector3(NeckWeigth, NeckLength, NeckWidgth)); //private Vector3 viewOffset; // 0x38

			if (GetAsyncKeyState(VK_PRIOR) & 1)
			{
				NeckLength++;
			}
			if (GetAsyncKeyState(VK_NEXT) & 1)
			{
				NeckLength--;
			}

			if (GetAsyncKeyState(VK_LEFT) & 1)
			{
				NeckWeigth--;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 1)
			{
				NeckWeigth++;
			}
			if (GetAsyncKeyState(VK_UP) & 1)
			{
				NeckWidgth++;
			}
			if (GetAsyncKeyState(VK_DOWN) & 1)
			{
				NeckWidgth--;
			}
			if (GetAsyncKeyState(VK_HOME) & 1)
			{
				NeckLength = 0.f;
				NeckWeigth = 0.f;
				NeckWidgth = 0.f;
			}
		}
		if (longneck)
		{
			auto eyes = driver.read<uintptr_t>(Local_Player + oPlayerEyes);
			driver.write<Vector3>(eyes + 0x38, Vector3(0.f, 2.0f, 0.f)); //private Vector3 viewOffset; // 0x38
		}
		if (timer)
		{
			auto time = driver.read<uintptr_t>(g_unityplayer + 0x17C1CD0 + 7 * 8);
			if (time) {
				if (GetAsyncKeyState(hangingg))
				{
					driver.write<float>(time + 0xFC, timervalue);
				}
				else {
					driver.write<float>(time + 0xFC, 1.f);
				}
			}
		}
		//auto ItemName = get_item_name(current_item);
		//std::string wsTmp(ItemName.begin(), ItemName.end());
		//std::string text = wsTmp;
		//std::cout << text << std::endl;

		bool ismeele = is_meele(current_item);
		if (ismeele) {
			if (supermeele)
			{
				if (driver.read<float>(base_projectile + omaxDistance) != 3.0f) {
					driver.write<float>(base_projectile + omaxDistance, 3.0f);
				}
				if (driver.read<float>(base_projectile + oAttackRadius) != 1.0f) {
					driver.write<float>(base_projectile + oAttackRadius, 1.0f);
				}

				if (driver.read<bool>(base_projectile + oBlockSprintOnAttack) != false) {
					driver.write<bool>(base_projectile + oBlockSprintOnAttack, false);
					driver.write<bool>(base_projectile + oonlyThrowAsProjectile, false);
					driver.write<bool>(base_projectile + othrowReady, true);
				}
			}
		}
		bool isWeapon = is_weapon(current_item);

		//std::wcout << get_item_name(current_item) << std::endl;

		if (isWeapon) {
			if (norecoil) {
				if (newRecoilOverride) {
						driver.write<int>(newRecoilOverride + oRecoilYawMin, 0);
						driver.write<int>(newRecoilOverride + oRecoilYawMax, 0);
						driver.write<int>(newRecoilOverride + oRecoilPitchMin, 0);
						driver.write<int>(newRecoilOverride + oRecoilPitchMax, 0);
				}
				if (!newRecoilOverride) {
						driver.write<int>(recoil_prop + oRecoilYawMin, 0);
						driver.write<int>(recoil_prop + oRecoilYawMax, 0);
						driver.write<int>(recoil_prop + oRecoilPitchMin, 0);
						driver.write<int>(recoil_prop + oRecoilPitchMax, 0);
				}
			}
			if (noshotgunspread)
			{
				auto List = driver.read<uintptr_t>(base_projectile + 0x370); // private List<Projectile> createdProjectiles;
				int size = driver.read<int>(List + 0x18);
				auto listt = driver.read<uintptr_t>(List + 0x10);
				for (int i = 0; i < size; ++i)
				{
					auto Projectile = driver.read<uintptr_t>(listt + 0x20 + (i * 0x8));
					auto ProjectileMod = driver.read<uintptr_t>(Projectile + 0xE8);

					driver.write<float>(ProjectileMod + 0x30, 0.f); // public float initialDistance;
					driver.write<float>(ProjectileMod + 0x38, 0.f); // public float stickProbability;
				}
			}
			if (fat_bullet_checkbox)
			{

				auto List = driver.read<uintptr_t>(base_projectile + 0x370); //private List<Projectile> createdProjectiles;
				int size = driver.read<uintptr_t>(List + 0x18);
				List = driver.read<uintptr_t>(List + 0x10);
				for (int i = 0; i < size; ++i)
				{
					auto Item = driver.read<uintptr_t>(List + 0x20 + (i * 0x8));
					if (driver.read<float>(Item + 0x2C) != 0.7f) {
						driver.write<float>(Item + 0x2C, 0.7f);
					}
				}
			}		
			if (nospread)
			{

				if (newRecoilOverride)
				{
					driver.write<int>(newRecoilOverride + oAimconeCurveScale, -1);
					driver.write<int>(newRecoilOverride + oStancePenalty, -1);
					driver.write<int>(newRecoilOverride + oAimCone, -1);
					driver.write<int>(newRecoilOverride + oHipAimCone, -1);
					driver.write<int>(newRecoilOverride + oAimconePenaltyPerShot, -1);

				}
				else
				{
					driver.write<int>(recoil_prop + oAimconeCurveScale, -1);
					driver.write<int>(recoil_prop + oStancePenalty, -1);
					driver.write<int>(recoil_prop + oAimCone, -1);
					driver.write<int>(recoil_prop + oHipAimCone, -1);
					driver.write<int>(recoil_prop + oAimconePenaltyPerShot, -1);
				}
			}

			if (full_automatic_checkbox)
			{
				if (driver.read<bool>(base_projectile + oAutomatic) != full_automatic_checkbox) {
					driver.write<bool>(base_projectile + oAutomatic, full_automatic_checkbox);
				}
			}

			if (nosway)
			{
				if (driver.read<float>(base_projectile + 0x2D8) != 0.f) {
					driver.write<float>(base_projectile + 0x2D8, 0.f);// public float aimSway;
				}
				if (driver.read<float>(base_projectile + 0x2DC) != 0.f) {
					driver.write<float>(base_projectile + 0x2DC, 0.f);// public float aimSwaySpeed;
				}
			}
			if (super_eoka_checkbox)
			{
				if (eokatamiri == false)
				{
					if (driver.read<float>(base_projectile + 0x378) != 100.f) {
						driver.write<float>(base_projectile + 0x378, 100.f); // successFraction
					}
					eokatamiri = true;
				}
				if (driver.read<bool>(base_projectile + 0x388) != true) {
					driver.write<bool>(base_projectile + 0x388, true); // didSparkThisFrame
				}
			}
			else
			{
				eokatamiri = false;
			}
			if (instantCompound == true)
			{
				if (driver.read<float>(base_projectile + 0x390) != 0) {
					driver.write<float>(base_projectile + 0x390, 0);//stringHoldDurationMax
				}
				if (driver.read<float>(base_projectile + 0x394) != 1000000) {
					driver.write<float>(base_projectile + 0x394, 1000000);//stringBonusDamage
					driver.write<float>(base_projectile + 0x3A0, 1000000);//movementPenaltyRampUpTime
				}
			}
			if (instabow == true)
			{
				driver.write<bool>(base_projectile + 0x360, true); // private bool triggerReady; // 0x360
				driver.write<float>(base_projectile + 0x364, 9999.f);
			}
		}
		if (fakelag == true)
		{
			driver.write<float>(Local_Player + 0x654, 0.8f); // public float serverTickInterval; // 0x658
			driver.write<float>(Local_Player + 0x658, 0.10f); // public float clientTickInterval; // 0x658
		}
		if (spinbot == true) {
			auto aPlayerInput = driver.read<uintptr_t>(Local_Player + oPlayerInput);
			driver.write<Vector4>(aPlayerInput + bodyRotation, Vector4(16.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
			driver.write<Vector4>(aPlayerInput + bodyRotation, Vector4(-16.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
			auto aPlayerInput1 = driver.read<uintptr_t>(Local_Player + oPlayerInput);
			driver.write<Vector4>(aPlayerInput1 + headRotation, Vector4(-5.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
			driver.write<Vector4>(aPlayerInput1 + headRotation, Vector4(22.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
			driver.write<Vector4>(aPlayerInput + bodyRotation, Vector4(-100.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
			driver.write<Vector4>(aPlayerInput + bodyRotation, Vector4(60.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
			driver.write<Vector4>(aPlayerInput + headRotation, Vector4(-100.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
			driver.write<Vector4>(aPlayerInput + headRotation, Vector4(30.0f, (0), 0, (RANDOMVECTOR(), (0), 0)));
		}

		
		

		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
}

bool homee = true;


std::vector<BasePlayer*> enemy_list;
std::vector<BasePlayer*> enemy_listTunnel;
std::vector<BasePlayer*> enemy_listScientist;

std::vector<DWORD64> BackPack;
std::vector<DWORD64> Corpse;

std::vector<DWORD64> StoneOre;
std::vector<DWORD64> SulfurOre;
std::vector<DWORD64> MetalOre;

std::vector<DWORD64> Stone;
std::vector<DWORD64> Sulfur;
std::vector<DWORD64> Metal;

std::vector<DWORD64> Hemp;

std::vector<DWORD64> mushroom1;
std::vector<DWORD64> mushroom2;

std::vector<DWORD64> AirDrop;

std::vector<DWORD64> MiniCopter;
std::vector<DWORD64> Carss;
std::vector<DWORD64> ScrapHeli;
std::vector<DWORD64> PatrolHeli;
std::vector<DWORD64> Boat;
std::vector<DWORD64> Rhib;
std::vector<DWORD64> Horsee;

std::vector<DWORD64> Stash;

std::vector<DWORD64> Military;
std::vector<DWORD64> Elite;
std::vector<DWORD64> Loot;
std::vector<DWORD64> Food;
std::vector<DWORD64> Medical;
std::vector<DWORD64> ToolBox;

std::vector<DWORD64> AutoTurret;
std::vector<DWORD64> ToolCupboard;

std::vector<DWORD64> Wolf;
std::vector<DWORD64> Bear;
std::vector<DWORD64> Stag;
std::vector<DWORD64> Chicken;
std::vector<DWORD64> Boar;

std::vector<DWORD64> RifleAk;
std::vector<DWORD64> RifleAkIce;
std::vector<DWORD64> Revolver;
std::vector<DWORD64> Python;
std::vector<DWORD64> HuntingBow;
std::vector<DWORD64> Compound;
std::vector<DWORD64> DoubleShotgun;
std::vector<DWORD64> Nailgun;
std::vector<DWORD64> Thompson;
std::vector<DWORD64> pSemi;
std::vector<DWORD64> Semi;
std::vector<DWORD64> WaterPipe;
std::vector<DWORD64> Spas12;
std::vector<DWORD64> M39;
std::vector<DWORD64> M92;
std::vector<DWORD64> MP5;
std::vector<DWORD64> SMG;
std::vector<DWORD64> Pump6;
std::vector<DWORD64> M249;
std::vector<DWORD64> L96;
std::vector<DWORD64> Bolt;
std::vector<DWORD64> Hmlmg;
std::vector<DWORD64> Eoka;
std::vector<DWORD64> Multiplegrenad;
std::vector<DWORD64> RocketLauncher;
std::vector<DWORD64> LR300;
void cheat()
{
	bool LP_isValid = false;	
	while (true)
	{
		/*	uintptr_t buffer_list = driver.read_chain(g_assembly, { BaseEntity, 0xB8, 0x10, 0x10, 0x28 });
			if (!buffer_list)
				buffer_list = driver.read_chain(g_assembly, { BaseEntity, 0xB8, 0x40, 0x10, 0x28 });
			auto objectList = driver.read<uintptr_t>(buffer_list + 0x18);
			auto objectListSize = driver.read<uint32_t>(buffer_list + 0x10);
			if (!objectListSize)
				return;*/
		auto main_offsets = driver.read<uintptr_t>(g_assembly + BaseGameMode);
		Local_Player = driver.read_chain(main_offsets, { 0xb8, 0x20, 0x10, 0x28, 0x18, 0x20 });

		const auto camera_manager_offset = driver.read<uintptr_t>(g_unityplayer + 0x1762E80);
		const auto camera_manager = driver.read<uintptr_t>(camera_manager_offset);
		const auto camera = driver.read<uintptr_t>(camera_manager);
		const auto camera_object = driver.read<uintptr_t>(camera + 0x30);
		if (!camera_object)
			return;

		const auto object_class = driver.read<uintptr_t>(camera_object + 0x30);
		if (!object_class)
			return;
		const auto Entityy = driver.read<uintptr_t>(object_class + 0x18);
		if (!Entityy)
			return;
		LocalPlayer.pViewMatrix = (Matrix4x4*)(Entityy + 0x2E4);

		uintptr_t BaseGameModee = driver.read<uintptr_t>(g_assembly + BaseGameMode);
		uintptr_t h1 = driver.read<uintptr_t>(BaseGameModee + 0xB8);
		uintptr_t h2 = driver.read<uintptr_t>(h1 + 0x20);
		uintptr_t h3 = driver.read<uintptr_t>(h2 + 0x10);
		uintptr_t h4 = driver.read<uintptr_t>(h3 + 0x28);
		auto objectList = driver.read<uintptr_t>(h4 + 0x18);
		auto objectListSize = driver.read<uint32_t>(h4 + 0x10);
		if (!objectListSize)
			return;

		for (int i = 0; i < objectListSize; i++) {
			auto curObject = driver.read<uintptr_t>(objectList + (0x20 + (i * 8)));
			auto baseObject = driver.read<uintptr_t>(curObject + 0x10);
			auto object = driver.read<uintptr_t>(baseObject + 0x30);
			auto tag = driver.read<WORD>(object + 0x54);
			auto buff = readchar(driver.read<uintptr_t>(object + 0x60));
			Entity = driver.read<uintptr_t>(objectList + 0x20 + (i * 0x8)); if (Entity <= 100000) continue;
			uintptr_t Object = driver.read<uintptr_t>(Entity + 0x10); if (Object <= 100000) continue;
			uintptr_t ObjectClass = driver.read<uintptr_t>(Object + 0x30); if (ObjectClass <= 100000) continue;


			auto SKY_C = driver.read<uintptr_t>(g_assembly + TodSkyy); // "Signature": "TOD_Sky_c*"
			auto SKYINSTANCE = driver.read<uintptr_t>(SKY_C + 0xB8);
			auto SKYINSTANCELIST = driver.read<uintptr_t>(SKYINSTANCE + 0x0);
			auto INSTANCES = driver.read<uintptr_t>(SKYINSTANCELIST + 0x10);
			auto Dome = driver.read<uintptr_t>(INSTANCES + 0x20);

			//auto TodCycle = driver.read<uintptr_t>(Dome + 0x38);
			//driver.write<float>(TodCycle + 0x10, 12.f); // Always day

			//auto Stars = driver.read<uintptr_t>(Dome + 0x70);
			//driver.write<float>(Stars + 0x10, 1.0f); //MESH SIZE
			//driver.write<float>(Stars + 0x14, 150.0f); //MESH BRIGHTNESS
			//driver.write<int>(Stars + 0x18, 1); //MESH Position

			////MOON SHIT
			//auto Moon = driver.read<uintptr_t>(Dome + 0x68);
			//driver.write<float>(Moon + 0x14, 6.0f); //MESH BRIGHTNESS
			//driver.write<float>(Moon + 0x10, 5.0f); //MESH SIZE
			//driver.write<float>(Moon + 0x18, 1.0f); //MESH CONTRAST
			//driver.write<float>(Moon + 0x24, 5.0f); //POSITION
			////MOON COLOR SHIT
			//auto Night = driver.read<uintptr_t>(Dome + 0x58);
			//auto MoonColorPtr = driver.read<uintptr_t>(Night + 0x10);
			//auto MoonColor = driver.read<uintptr_t>(MoonColorPtr + 0x10);
			//driver.write<float>(MoonColor, 1.0f);
			//driver.write<float>(MoonColor + 0x4, 1.0f);
			//driver.write<float>(MoonColor + 0x8, 0.6f);

			//driver.write<float>(MoonColor + 0xC, 0.6f);
			//driver.write<float>(MoonColor + 0x10, 0.6f);

			//driver.write<float>(MoonColor + 0x14, 0.0f);
			//driver.write<float>(MoonColor + 0x18, 1.0f);
			//driver.write<float>(MoonColor + 0x1C, 1.0f);

			//auto StarQuality = driver.read<uintptr_t>(Dome + 0x30);
			//driver.write<float>(StarQuality + 0x0, 2);

			if (chams)
			{
				if (!chamstamiri)
				{
					uintptr_t player_model = driver.read<uintptr_t>(Entity + 0x4D0); // public PlayerModel playerModel;

					auto components = driver.read<uintptr_t>(Dome + 0xA8);
					auto scattering = driver.read<uintptr_t>(components + 0x1A0);
					auto material = driver.read<uintptr_t>(scattering + 0x78);

					//Cinsiyet 1
					auto player_skin_component = driver.read<uintptr_t>(player_model + 0x1A0); // public SkinSetCollection MaleSkin; // 0x1A0
					auto skins = driver.read<uintptr_t>(player_skin_component + 0x18);
					auto skins_sz = driver.read<int32_t>(skins + 0x18);
					for (int i = NULL; i <= (int)skins_sz; i++)
					{
						auto current_skin = driver.read<uintptr_t>(skins + 0x20 + (i * 0x8));

						driver.write<uintptr_t>(current_skin + 0x68, material);
						driver.write<uintptr_t>(current_skin + 0x70, material);
						driver.write<uintptr_t>(current_skin + 0x78, material);
					}
					//Cinsiyet 2
					auto player_skin_component2 = driver.read<uintptr_t>(player_model + 0x1A8); // public SkinSetCollection MaleSkin; // 0x1A0
					auto skins2 = driver.read<uintptr_t>(player_skin_component2 + 0x18);
					auto skins_sz2 = driver.read<int32_t>(skins2 + 0x18);
					for (int i = NULL; i <= (int)skins_sz2; i++)
					{
						auto current_skin2 = driver.read<uintptr_t>(skins2 + 0x20 + (i * 0x8));

						driver.write<uintptr_t>(current_skin2 + 0x68, material);
						driver.write<uintptr_t>(current_skin2 + 0x70, material);
						driver.write<uintptr_t>(current_skin2 + 0x78, material);
					}
					chamstamiri = true;
				}
			}
			else
			{
				chamstamiri = false;
			}
			BasePlayer* Player = (BasePlayer*)driver.read<DWORD64>(Object + 0x28); //public ulong playerID;
			if (buff.find(skCrypt("Local")) != std::string::npos) {
				BasePlayer* Player = driver.read<BasePlayer*>(baseObject + 0x28);
				if (Player != LocalPlayer.BasePlayer) {}
				LocalPlayer.BasePlayer = Player;
				LP_isValid = true;
			}
			if (buff.find(skCrypt("player.prefab")) != std::string::npos)
			{
				enemy_list.push_back(Player);
			}
			if (buff.find(skCrypt("tunneldweller.prefab")) != std::string::npos)
			{
				enemy_listTunnel.push_back(Player);
			}
			if (buff.find(skCrypt("scientistnpc")) != std::string::npos)
			{
				enemy_listScientist.push_back(Player);
			}
			if (buff.find(skCrypt("item_drop_backpack")) != std::string::npos)
			{
				BackPack.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("player_corpse")) != std::string::npos)
			{
				Corpse.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("stone-ore.prefab")) != std::string::npos)
			{
				StoneOre.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("sulfur-ore.prefab")) != std::string::npos)
			{
				SulfurOre.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("metal-ore.prefab")) != std::string::npos)
			{
				MetalOre.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("stone-collectable.prefab")) != std::string::npos)
			{
				Stone.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("sulfur-collectable.prefab")) != std::string::npos)
			{
				Sulfur.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("metal-collectable.prefab")) != std::string::npos)
			{
				Metal.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("hemp-collectable.prefab")) != std::string::npos)
			{
				Hemp.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("mushroom-cluster-5.prefab")) != std::string::npos)
			{
				mushroom1.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("mushroom-cluster-6.prefab")) != std::string::npos)
			{
				mushroom2.push_back(ObjectClass);
			}
     		if (buff.find(skCrypt("supply_drop.prefab")) != std::string::npos)
			{
				AirDrop.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("minicopter.entity.prefab")) != std::string::npos)
			{
				MiniCopter.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("car_")) != std::string::npos)
			{
				Carss.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("scraptransporthelicopter")) != std::string::npos)
			{
				ScrapHeli.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("patrolhelicopter")) != std::string::npos)
			{
				PatrolHeli.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("rowboat.prefab")) != std::string::npos)
			{
				Boat.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("rhib.prefab")) != std::string::npos)
			{
				Rhib.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("testridablehorse.prefab")) != std::string::npos)
			{
				Horsee.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("small_stash_deployed.prefab")) != std::string::npos)
			{
				Stash.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("crate_normal.prefab")) != std::string::npos)
			{
				Military.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("crate_elite.prefab")) != std::string::npos)
			{
				Elite.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("crate_normal_2.prefab")) != std::string::npos)
			{
				Loot.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("crate_normal_2_food.prefab")) != std::string::npos)
			{
				Food.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("crate_normal_2_medical.prefab")) != std::string::npos)
			{
				Medical.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("crate_tools.prefab")) != std::string::npos)
			{
				ToolBox.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("autoturret.prefab")) != std::string::npos)
			{
				AutoTurret.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("cupboard.tool.deployed.prefab")) != std::string::npos)
			{
				ToolCupboard.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("wolf.prefab")) != std::string::npos)
			{
				Wolf.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("bear.prefab")) != std::string::npos)
			{
				Bear.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("stag.prefab")) != std::string::npos)
			{
				Stag.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("chicken.prefab")) != std::string::npos)
			{
				Chicken.push_back(ObjectClass);
			}
			if (buff.find(skCrypt("boar.prefab")) != std::string::npos)
			{
				Boar.push_back(ObjectClass);
			}
			if (weapons)
			{
				if (buff.find(skCrypt("rifle.ak")) != std::string::npos)
				{
					RifleAk.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("rifle.ak.ice")) != std::string::npos)
				{
					RifleAkIce.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("pistol.revolve")) != std::string::npos)
				{
					Revolver.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("pistol.python")) != std::string::npos)
				{
					Python.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("bow.hunting")) != std::string::npos)
				{
					HuntingBow.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("bow.compound")) != std::string::npos)
				{
					Compound.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("shotgun.double")) != std::string::npos)
				{
					DoubleShotgun.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("pistol.nailgun")) != std::string::npos)
				{
					Nailgun.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("smg.thompson")) != std::string::npos)
				{
					Thompson.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("pistol.semiaut")) != std::string::npos)
				{
					pSemi.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("rifle.semiauto")) != std::string::npos)
				{
					Semi.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("shotgun.waterp")) != std::string::npos)
				{
					WaterPipe.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("shotgun.spas12")) != std::string::npos)
				{
					Spas12.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("rifle.m39")) != std::string::npos)
				{
					M39.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("pistol.m92")) != std::string::npos)
				{
					M92.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("smg.mp5")) != std::string::npos)
				{
					MP5.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("smg.2")) != std::string::npos)
				{
					SMG.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("shotgun.pump")) != std::string::npos)
				{
					Pump6.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("lmg.m249")) != std::string::npos)
				{
					M249.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("rifle.l96")) != std::string::npos)
				{
					L96.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("rifle.bolt")) != std::string::npos)
				{
					Bolt.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("lmg.hmlmg")) != std::string::npos)
				{
					Hmlmg.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("pistol.eoka")) != std::string::npos)
				{
					Eoka.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("multiplegrenad")) != std::string::npos)
				{
					Multiplegrenad.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("rocket.launche")) != std::string::npos)
				{
					RocketLauncher.push_back(ObjectClass);
				}
				if (buff.find(skCrypt("rifle.lr300")) != std::string::npos)
				{
					LR300.push_back(ObjectClass);
				}
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10000));
		enemy_list.clear();
		enemy_listTunnel.clear();
		enemy_listScientist.clear();
		BackPack.clear();
		Corpse.clear();
		StoneOre.clear();
		SulfurOre.clear();
		MetalOre.clear();
		Stone.clear();
		Sulfur.clear();
		Metal.clear();
		Hemp.clear();
		mushroom1.clear();
		mushroom2.clear();
		AirDrop.clear();
		MiniCopter.clear();
		Carss.clear();
		ScrapHeli.clear();
		ScrapHeli.clear();
		PatrolHeli.clear();
		Boat.clear();
		Rhib.clear();
		Horsee.clear();
		Stash.clear();
		Military.clear();
		Elite.clear();
		Loot.clear();
		Food.clear();
		Medical.clear();
		ToolBox.clear();
		AutoTurret.clear();
		ToolCupboard.clear();
		Wolf.clear();
		Bear.clear();
		Stag.clear();
		Chicken.clear();
		Boar.clear();
		if (weapons)
		{
			RifleAk.clear();
			RifleAkIce.clear();
			Revolver.clear();
			Python.clear();
			HuntingBow.clear();
			Compound.clear();
			DoubleShotgun.clear();
			Nailgun.clear();
			Thompson.clear();
			pSemi.clear();
			Semi.clear();
			WaterPipe.clear();
			Spas12.clear();
			M39.clear();
			M92.clear();
			MP5.clear();
			SMG.clear();
			Pump6.clear();
			M249.clear();
			L96.clear();
			Bolt.clear();
			Hmlmg.clear();
			Eoka.clear();
			Multiplegrenad.clear();
			RocketLauncher.clear();
			LR300.clear();
		}
	}
}

void draw()
{
	for (auto Player : enemy_list)
	{
		ESP_Player(Player);
		/*if (AimFov(Player) < aimfovv)
		{
			aimbott(Player);
		}*/
		if (playerinfoo)
		{
			if (AimFov(Player) < 30)
			{
				playerinfo(Player);
			}
		}
	}
	if (tunneldweller)
	{
		for (auto Player : enemy_listTunnel)
		{

			ESP_Scientist(Player, true);
			if (ssilent)
			{
				sLocalPlayerHead = LocalPlayer.BasePlayer->Position2();
				sTargetBonePos = Player->Position2();
				Vector3 sTargetAngles = CalcAngle(sLocalPlayerHead, sTargetBonePos);
				Vector2 sAngles; sAngles.x = sTargetAngles.x, sAngles.y = sTargetAngles.y;

				if (Predictionn) {
					sTargetBonePos = Prediction(sLocalPlayerHead, Player, BoneList(head), sTargetBonePos);
				}

				if (AimFov(Player) < aimfovv)
				{
					/*if (ssilent && GetAsyncKeyState(aimkey)) {
						auto eyes = driver.read<uintptr_t>((uintptr_t)LocalPlayer.BasePlayer + oPlayerEyes);
						Vector4 sQuatAngles = ToQuat({ sAngles.x, sAngles.y, 0.0f });
						driver.write<Vector4>(eyes + 0x44, sQuatAngles);
					}*/
					if (ssilent && GetAsyncKeyState(aimkey)) {
						LocalPlayer.BasePlayer->SetVA(sAngles);
					}
				}	
			}
		}
	}
	if (scientistnpc)
	{
		for (auto Player : enemy_listScientist)
		{

			ESP_Scientist(Player, false);
			if (ssilent)
			{
				sLocalPlayerHead = LocalPlayer.BasePlayer->Position2();
				sTargetBonePos = Player->Position2();
				Vector3 sTargetAngles = CalcAngle(sLocalPlayerHead, sTargetBonePos);
				Vector2 sAngles; sAngles.x = sTargetAngles.x, sAngles.y = sTargetAngles.y;

				if (Predictionn) {
					sTargetBonePos = Prediction(sLocalPlayerHead, Player, BoneList(head), sTargetBonePos);
				}

				if (AimFov(Player) < aimfovv)
				{
				/*	if (ssilent && GetAsyncKeyState(aimkey)) {
						auto eyes = driver.read<uintptr_t>((uintptr_t)LocalPlayer.BasePlayer + oPlayerEyes);
						Vector4 sQuatAngles = ToQuat({ sAngles.x, sAngles.y, 0.0f });
						driver.write<Vector4>(eyes + 0x44, sQuatAngles);
					}*/
					if (ssilent && GetAsyncKeyState(aimkey)) {
						LocalPlayer.BasePlayer->SetVA(sAngles);
					}
				}
			}
		}
	}
	if (backpack)
	{
		for (auto Player : BackPack)
		{

			ESP_Resource(Player, true, 300, skCrypt(L"Backpack"), &Col.white);
		}
	}
	if (playercorpse)
	{
		for (auto Player : Corpse)
		{

			ESP_Resource(Player, true, 300, skCrypt(L"Corpse"), &Col.white);
		}
	}
	if (stone)
	{
		for (auto Player : StoneOre)
		{

			ESP_Resource(Player, true, 300, skCrypt(L"Stone Ore"), &Col.white);
		}
	}
	if (sulfur)
	{
		for (auto Player : SulfurOre)
		{

			ESP_Resource(Player, true, 300, skCrypt(L"Sulfur Ore"), &Col.darkyellow_);
		}
	}
	if (metal)
	{
		for (auto Player : MetalOre)
		{

			ESP_Resource(Player, true, 300, skCrypt(L"Metal Ore"), &Col.gray_);
		}
	}
	if (stone2)
	{
		for (auto Player : Stone)
		{

			ESP_Resource(Player, true, 300, skCrypt(L"Stone"), &Col.white);
		}
	}
	if (sulfur2)
	{
		for (auto Player : Sulfur)
		{

			ESP_Resource(Player, true, 300, skCrypt(L"Sulfur"), &Col.darkyellow_);
		}
	}
	if (metal2)
	{
		for (auto Player : Metal)
		{

			ESP_Resource(Player, true, 300, skCrypt(L"Metal"), &Col.gray_);
		}
	}
	if (hemp)
	{
		for (auto Player : Hemp)
		{

			ESP_Resource(Player, true, 300, skCrypt(L"Hemp"), &Col.greens);
		}
	}
	if (mushroom)
	{
		for (auto Player : mushroom1)
		{

			ESP_Resource(Player, true, 300, skCrypt(L"Mushroom"), &Col.orange_);
		}
	}
	if (mushroom)
	{
		for (auto Player : mushroom2)
		{

			ESP_Resource(Player, true, 300, skCrypt(L"Mushroom"), &Col.orange_);
		}
	}
	if (airdrop)
	{
		for (auto Player : AirDrop)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Airdrop"), &Col.yellow_);	
		}
	}
	if (minicopter)
	{
		for (auto Player : MiniCopter)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Minicopter"), &Col.silverwhite_);
		}
	}
	if (cars)
	{
		for (auto Player : Carss)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Car"), &Col.silverwhite_);
		}
	}
	if (scrapheli)
	{
		for (auto Player : ScrapHeli)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Scrap Heli"), &Col.silverwhite_);
		}
	}
	if (patrolheli)
	{
		for (auto Player : PatrolHeli)
		{
			ESP_Resource(Player, true, 50000, skCrypt(L"Patrol Heli"), &Col.silverwhite_);
		}
	}
	if (boat)
	{
		for (auto Player : Boat)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Boat"), &Col.silverwhite_);
		}
	}
	if (rhib)
	{
		for (auto Player : Rhib)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Rhib"), &Col.silverwhite_);
		}
	}
	if (horse)
	{
		for (auto Player : Horsee)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Horse"), &Col.neger);
		}
	}
	if (stash)
	{
		for (auto Player : Stash)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Stash"), &Col.yellow_);
		}
	}
	if (military)
	{
		for (auto Player : Military)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Military Crate"), &Col.SilverWhite);
		}
	}
	if (elite)
	{
		for (auto Player : Elite)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Elite Crate"), &Col.SilverWhite);
		}
	}
	if (loot)
	{
		for (auto Player : Loot)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Loot Crate"), &Col.SilverWhite);
		}
	}
	if (food)
	{
		for (auto Player : Food)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Food Crate"), &Col.SilverWhite);
		}
	}
	if (medical)
	{
		for (auto Player : Medical)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Medical Crate"), &Col.SilverWhite);
		}
	}
	if (toolbox)
	{
		for (auto Player : ToolBox)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Tool Crate"), &Col.SilverWhite);
		}
	}
	if (autoturret)
	{
		for (auto Player : AutoTurret)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Auto Turret"), &Col.SilverWhite);
		}
	}
	if (toolcupboard)
	{
		for (auto Player : ToolCupboard)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Tool Cupboard"), &Col.SilverWhite);
		}
	}
	if (wolf)
	{
	for (auto Player : Wolf)
	{
	
			ESP_Resource(Player, true, 50000, skCrypt(L"Wolf"), &Col.neger);
		}
	}
	if (bear)
	{
	for (auto Player : Bear)
	{
	
			ESP_Resource(Player, true, 50000, skCrypt(L"Bear"), &Col.neger);
		}
	}
	if (stag)
	{
	for (auto Player : Stag)
	{
	
			ESP_Resource(Player, true, 50000, skCrypt(L"Stag"), &Col.neger);
		}
	}
	if (chicken)
	{
	for (auto Player : Chicken)
	{
	
			ESP_Resource(Player, true, 50000, skCrypt(L"Chicken"), &Col.neger);
		}
	}
	if (boar)
	{
		for (auto Player : Boar)
		{
			ESP_Resource(Player, true, 50000, skCrypt(L"Boar"), &Col.neger);
		}
	}
	if (weapons)
	{
		for (auto Player : RifleAk)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"AK-47"), &Col.darkyellow_);

		}
		for (auto Player : RifleAkIce)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"AK-47"), &Col.darkyellow_);

		}
		for (auto Player : Revolver)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Revolver"), &Col.darkyellow_);

		}
		for (auto Player : Python)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Python"), &Col.darkyellow_);

		}
		for (auto Player : HuntingBow)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Hunting Bow"), &Col.darkyellow_);

		}
		for (auto Player : Compound)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Compound Bow"), &Col.darkyellow_);

		}
		for (auto Player : DoubleShotgun)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Double Barrel"), &Col.darkyellow_);

		}
		for (auto Player : Nailgun)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Nailgun"), &Col.darkyellow_);

		}
		for (auto Player : Thompson)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Thompson"), &Col.darkyellow_);

		}
		for (auto Player : pSemi)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Pistol Semiauto"), &Col.darkyellow_);

		}
		for (auto Player : Semi)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Rifle Semiauto"), &Col.darkyellow_);

		}
		for (auto Player : WaterPipe)
		{
			ESP_Resource(Player, true, 50000, skCrypt(L"Waterpipe Shotgun"), &Col.darkyellow_);

		}
		for (auto Player : Spas12)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Spas12 Shotgun"), &Col.darkyellow_);

		}
		for (auto Player : M39)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"M39"), &Col.darkyellow_);

		}
		for (auto Player : M92)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"M92 Pistol"), &Col.darkyellow_);

		}
		for (auto Player : MP5)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"MP5A4"), &Col.darkyellow_);

		}
		for (auto Player : SMG)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"SMG"), &Col.darkyellow_);

		}
		for (auto Player : Pump6)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Pump Shotgun"), &Col.darkyellow_);

		}
		for (auto Player : M249)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"M249"), &Col.darkyellow_);

		}
		for (auto Player : L96)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"L96 Rifle"), &Col.darkyellow_);

		}
		for (auto Player : Bolt)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"Bolt Rifle"), &Col.darkyellow_);

		}
		for (auto Player : Hmlmg)
		{

			ESP_Resource(Player, true, 50000, skCrypt(L"HMLMG"), &Col.darkyellow_);

		}
		for (auto Player : Eoka)
		{
			ESP_Resource(Player, true, 50000, skCrypt(L"Eoka"), &Col.darkyellow_);

		}
		for (auto Player : Multiplegrenad)
		{
			ESP_Resource(Player, true, 50000, skCrypt(L"Grenade Launcher"), &Col.darkyellow_);
		}
		for (auto Player : RocketLauncher)
		{
			ESP_Resource(Player, true, 50000, skCrypt(L"Rocket Launcher"), &Col.darkyellow_);
		}
		for (auto Player : LR300)
		{
			ESP_Resource(Player, true, 50000, skCrypt(L"LR300 Rifle"), &Col.darkyellow_);
		}
	}
}

int g_menuKeyBind = VK_INSERT;

void stylemenu2()
{
	ImGuiStyle& style = ImGui::GetStyle();
	//style.WindowRounding = 5.0f;
	//style.WindowBorderSize = 2.0f;

	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 0.85f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.17f, 0.17f, 0.17f, 0.85f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
	colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
	colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TableHeaderBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TableBorderStrong] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TableBorderLight] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);


	style.WindowPadding = ImVec2(8.00f, 8.00f);
	style.FramePadding = ImVec2(5.00f, 2.00f);
	style.CellPadding = ImVec2(6.00f, 6.00f);
	//style.ItemSpacing = ImVec2(6.00f, 6.00f);
	style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
	style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
	style.IndentSpacing = 25;
	style.ScrollbarSize = 15;
	style.GrabMinSize = 10;
	style.WindowBorderSize = 1;
	style.ChildBorderSize = 1;
	style.PopupBorderSize = 1;
	style.FrameBorderSize = 1;
	style.TabBorderSize = 1;
	style.WindowRounding = 7;
	style.ChildRounding = 4;
	style.FrameRounding = 3;
	style.PopupRounding = 4;
	style.ScrollbarRounding = 9;
	style.GrabRounding = 3;
	style.LogSliderDeadzone = 4;
	style.TabRounding = 4;
}

D3DCOLOR FLOAT4TOD3DCOLOR(float Col[])
{
	ImU32 col32_no_alpha = ImGui::ColorConvertFloat4ToU32(ImVec4(Col[0], Col[1], Col[2], Col[3]));
	float a = (col32_no_alpha >> 24) & 255;
	float r = (col32_no_alpha >> 16) & 255;
	float g = (col32_no_alpha >> 8) & 255;
	float b = col32_no_alpha & 255;
	return D3DCOLOR_ARGB((int)a, (int)r, (int)g, (int)b);
}

namespace Screen
{
	static int Width = GetSystemMetrics(SM_CXSCREEN);
	static int Height = GetSystemMetrics(SM_CYSCREEN);
}

namespace Colors
{
	float CrosshairColors[] = { 255.f, 55.f, 55.f, 255.f };
}


namespace crosshair
{
	namespace sizes
	{

		namespace cross
		{
			float length = 4.0f;
			float gap = 1.0f;
		}


	}
}
void Crosshair()
{
	auto RGB = ImGui::GetColorU32({ 255, 255, 255, 255 });
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(GetWindowSize().x / 2 + crosshair::sizes::cross::gap + 1, GetWindowSize().y / 2 - 1), ImVec2(GetWindowSize().x / 2 + crosshair::sizes::cross::length + crosshair::sizes::cross::gap + 1, GetWindowSize().y / 2 + 1), cRainbow);
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(GetWindowSize().x / 2 - crosshair::sizes::cross::gap - 1, GetWindowSize().y / 2 + 1), ImVec2(GetWindowSize().x / 2 - crosshair::sizes::cross::length - crosshair::sizes::cross::gap - 1, GetWindowSize().y / 2 - 1), cRainbow);
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(GetWindowSize().x / 2 - 1, GetWindowSize().y / 2 + crosshair::sizes::cross::gap + 1), ImVec2(GetWindowSize().x / 2 + 1, GetWindowSize().y / 2 + crosshair::sizes::cross::length + crosshair::sizes::cross::gap + 1), cRainbow);
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(GetWindowSize().x / 2 + 1, GetWindowSize().y / 2 - crosshair::sizes::cross::gap - 1), ImVec2(GetWindowSize().x / 2 - 1, GetWindowSize().y / 2 - crosshair::sizes::cross::length - crosshair::sizes::cross::gap - 1), cRainbow);
}
int tab = 1;
void draw_menu()
{
	auto s = ImVec2{}, p = ImVec2{}, gs = ImVec2{ 620, 485 };
	ImGui::SetNextWindowSize(ImVec2(gs));
	ImGui::SetNextWindowBgAlpha(1.0f);
	ImGui::Begin(skCrypt("ALIEN CHEATS - (ver. 0.0.2)"), NULL, ImGuiWindowFlags_::ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_::ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar);
	{
	
		ImGui::SetCursorPosX(121);
		s = ImVec2(ImGui::GetWindowSize().x - ImGui::GetStyle().WindowPadding.x * 2, ImGui::GetWindowSize().y - ImGui::GetStyle().WindowPadding.y * 2); p = ImVec2(ImGui::GetWindowPos().x + ImGui::GetStyle().WindowPadding.x, ImGui::GetWindowPos().y + ImGui::GetStyle().WindowPadding.y); auto draw = ImGui::GetWindowDrawList();
		draw->AddRectFilled(p, ImVec2(p.x + s.x, p.y + s.y), ImColor(15, 17, 19), 5);
		draw->AddRectFilled(ImVec2(p.x, p.y + 40), ImVec2(p.x + s.x, p.y + s.y), ImColor(18, 20, 21), 5, ImDrawCornerFlags_Bot);

		ImGui::PushFont(icons);
		auto logo_size = ImGui::CalcTextSize(skCrypt("A"));
		draw->AddText(ImVec2(p.x + 28 - logo_size.x / 2, p.y + 29 - (logo_size.y / 2) + 4), cRainbow, skCrypt("A"));
		ImGui::PopFont();

		ImGui::PushFont(main_font2);
		auto logo_size2 = ImGui::CalcTextSize(skCrypt("A"));
		draw->AddText(ImVec2(p.x + 42 - logo_size2.x / 2, p.y + 29 - logo_size2.y), cRainbow, skCrypt("AlienCheats"));
		ImGui::PopFont();
		ImGui::PushFont(main_font);
		draw->AddText(ImVec2(p.x + 42 - logo_size2.x / 2, p.y + 40 - logo_size2.y), cRainbow, "(PRIVATE)");
		ImGui::PopFont();

		ImGui::PushFont(main_font);
		ImGui::BeginGroup();
		ImGui::SameLine(60);
		if (ImGui::tab(skCrypt("AIMBOT"), tab == 1))tab = 1; ImGui::SameLine();
		if (ImGui::tab(skCrypt("ESP"), tab == 2))tab = 2; ImGui::SameLine();
		if (ImGui::tab(skCrypt("Visuals"), tab == 3))tab = 3; ImGui::SameLine();
		if (ImGui::tab(skCrypt("Misc"), tab == 4))tab = 4; ImGui::SameLine();
		if (ImGui::tab(skCrypt("Settings"), tab == 5))tab = 5;
		ImGui::EndGroup();
		ImGui::PopFont();

		if (tab == 1)
		{
			ImGui::PushFont(main_font);
			{//left upper
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(15);
				ImGui::MenuChild(skCrypt("Aimbot"), ImVec2(285, 415), false);
				{
					ImGui::Checkbox(skCrypt("Aim Bot"), &aimbot); 
					ImGui::Text(skCrypt("")); ImGui::SameLine(8); HotkeyButton(aimkey, ChangeKey, keystatus); ImGui::SameLine(); ImGui::Text(skCrypt("Aimbot Key"));
					ImGui::Checkbox(skCrypt("Silent"), &silent);
					//ImGui::Checkbox(skCrypt("Patrolhelicopter Silent"), &psilent);
					ImGui::Checkbox(skCrypt("Silent Line"), &silentline);
					ImGui::Checkbox(skCrypt("Scientist Aimbot"), &ssilent);
					ImGui::Checkbox(skCrypt("Prediction"), &Predictionn);
					ImGui::SliderFloat(skCrypt("Fov"), &aimfovv, 1, 360, "% .2f");
					ImGui::SliderFloat(skCrypt("Smooth"), &aimsmooth, 1, 10, "% .2f");
					ImGui::Checkbox(skCrypt("Sleeper Ignore"), &sleeperignore);
					ImGui::Checkbox(skCrypt("Team Ignore"), &teamignoree);
					ImGui::Checkbox(skCrypt("Wounded Ignore"), &woundedignore);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			{//right
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(320);
				ImGui::MenuChild(skCrypt("Weapon"), ImVec2(285, 415), false);
				{
					ImGui::Checkbox(skCrypt("No Recoil"), &norecoil);
					ImGui::Checkbox(skCrypt("No Spread"), &nospread);
					ImGui::Checkbox(skCrypt("Fat Bullet"), &fat_bullet_checkbox);
					ImGui::Checkbox(skCrypt("Automatic"), &full_automatic_checkbox);
					ImGui::Checkbox(skCrypt("No Sway"), &nosway);
					ImGui::Checkbox(skCrypt("Super Eoka"), &super_eoka_checkbox);
					ImGui::Checkbox(skCrypt("Super Meele"), &supermeele);
					ImGui::Checkbox(skCrypt("Shotgun No Spread"), &noshotgunspread);
					ImGui::Checkbox(skCrypt("Super Compound Bow"), &instantCompound);
					ImGui::Checkbox(skCrypt("Zoom"), &zoom);
					ImGui::Checkbox(skCrypt("ADS Hide"), &ADS_Hide);
					ImGui::Checkbox(skCrypt("Crosshair"), &cross);
					ImGui::Checkbox(skCrypt("InstaBow"), &instabow);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
				ImGui::PopFont();
			}
		}
		if (tab == 2)
		{
			ImGui::PushFont(main_font);
			{//left upper
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(15);
				ImGui::MenuChild(skCrypt("PLAYER esp"), ImVec2(285, 415), false);
				{
					ImGui::Checkbox(skCrypt("2D Box"), &box2); 
					ImGui::Checkbox(skCrypt("Corner Box"), &box);	
					ImGui::Checkbox(skCrypt("Skeleton"), &skeleton);
					ImGui::Checkbox(skCrypt("Name Tag"), &name);
					ImGui::Checkbox(skCrypt("Fill Box"), &paintinside);
					ImGui::Checkbox(skCrypt("Health Bar"), &healthbar); 
					ImGui::Checkbox(skCrypt("Snapline"), &snapline);
					ImGui::Checkbox(skCrypt("Weapon Info"), &handweapon);
					ImGui::Checkbox(skCrypt("Player info"), &playerinfoo); 
					ImGui::Checkbox(skCrypt("Chams"), &chams);
					ImGui::Checkbox(skCrypt("Sleep Ignore"), &sleeper);
					ImGui::Checkbox(skCrypt("Team Ignore"), &teamignore);
					ImGui::Checkbox(skCrypt("Show Distance"), &showdistance);
					ImGui::Checkbox(skCrypt("Wounded Alert"), &WoundedAlert);
					ImGui::Checkbox(skCrypt("Player Corpse"), &playercorpse);
					ImGui::Checkbox(skCrypt("Backpack"), &backpack);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			{//right
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(320);
				ImGui::MenuChild(skCrypt("MISC ESP"), ImVec2(285, 415), false);
				{
					ImGui::Checkbox(skCrypt("Wolf"), &wolf);
					ImGui::Checkbox(skCrypt("Bear"), &bear);
					ImGui::Checkbox(skCrypt("Stag"), &stag);
					ImGui::Checkbox(skCrypt("Chicken"), &chicken);
					ImGui::Checkbox(skCrypt("Boar"), &boar);
					ImGui::Checkbox(skCrypt("Horse"), &horse);
					ImGui::Separator();
					ImGui::Checkbox(skCrypt("Weapons"), &weapons);
					ImGui::Checkbox(skCrypt("Show Distance"), &showdistancee);
					ImGui::Separator();
					ImGui::Checkbox(skCrypt("Tunnel Dweller"), &tunneldweller);
					ImGui::Checkbox(skCrypt("Scientist NPC"), &scientistnpc);
					ImGui::Separator();
					ImGui::Checkbox(skCrypt("Airdrop"), &airdrop);
					ImGui::Checkbox(skCrypt("Stash"), &stash);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			ImGui::PopFont();
		}
		if (tab == 3)
		{
			ImGui::PushFont(main_font);
			{//left upper
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(15);
				ImGui::MenuChild(skCrypt("RESOURCES"), ImVec2(285, 415), false);
				{
					ImGui::Checkbox(skCrypt("Stone Ore"), &stone);
					ImGui::Checkbox(skCrypt("Stone"), &stone2);
					ImGui::Checkbox(skCrypt("Sulfur Ore"), &sulfur);
					ImGui::Checkbox(skCrypt("Sulfur"), &sulfur2);
					ImGui::Checkbox(skCrypt("Metal Ore"), &metal);
					ImGui::Checkbox(skCrypt("Metal"), &metal2);
					ImGui::Checkbox(skCrypt("Mushroom"), &mushroom);
					ImGui::Checkbox(skCrypt("Hemp"), &hemp);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			{//right
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(320);
				ImGui::MenuChild(skCrypt("LOOTS & VEHICLES"), ImVec2(285, 415), false);
				{
					ImGui::Checkbox(skCrypt("military crate"), &military);
					ImGui::Checkbox(skCrypt("elite crate"), &elite);
					ImGui::Checkbox(skCrypt("loot crate"), &loot);
					ImGui::Checkbox(skCrypt("food crate"), &food);
					ImGui::Checkbox(skCrypt("medical crate"), &medical);
					ImGui::Checkbox(skCrypt("toolbox crate"), &toolbox);
					ImGui::Separator();
					ImGui::Checkbox(skCrypt("Minicopter"), &minicopter);
					ImGui::Checkbox(skCrypt("Scrap Heli"), &scrapheli);
					ImGui::Checkbox(skCrypt("Patrol Heli"), &patrolheli);
					ImGui::Checkbox(skCrypt("Boat"), &boat);
					ImGui::Checkbox(skCrypt("Rhib"), &rhib);
					ImGui::Checkbox(skCrypt("Cars"), &cars);
					ImGui::Separator();
					ImGui::Checkbox(skCrypt("Auto Turret"), &autoturret);
					ImGui::Checkbox(skCrypt("Tool Cupboard"), &toolcupboard);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			ImGui::PopFont();
		}
		if (tab == 4)
		{
			ImGui::PushFont(main_font);
			{//left upper
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(15);
				ImGui::MenuChild(skCrypt("Functions"), ImVec2(285, 415), false);
				{
					ImGui::Checkbox(skCrypt("Admin Flag"), &admin_flag_checkboxx);
					ImGui::Checkbox(skCrypt("Graphic Fov"), &fov);
					ImGui::Checkbox(skCrypt("FakeWorkbench"), &fakeworkbench);
					ImGui::Checkbox(skCrypt("ThirdPerson"), &thirdperson);
					ImGui::Checkbox(skCrypt("Instantly Suicide"), &suicide);
					ImGui::Checkbox(skCrypt("Time Changer"), &alwaysday);
					ImGui::Checkbox(skCrypt("Night Mode"), &nighttmode);
					ImGui::Checkbox(skCrypt("Old Box ESP"), &AdminEsp);
					ImGui::Checkbox(skCrypt("Fake Lag"), &fakelag);
					ImGui::Checkbox(skCrypt("Spin Bot"), &spinbot);
					ImGui::Checkbox(skCrypt("HardCoreMode Map"), &hardcoremodeMap);
					ImGui::Checkbox(skCrypt("Camera [PGUP] [PGDOWN] [ARROW KEYS]"), &cameraaa);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			{//right
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(320);
				ImGui::MenuChild(skCrypt("MISC"), ImVec2(285, 415), false);
				{
					ImGui::Checkbox(skCrypt("Spiderman"), &spiderman);
					ImGui::Checkbox(skCrypt("Fly Hack [F]"), &flyhack);
					ImGui::Checkbox(skCrypt("Infinity Jump"), &infinitejump);
					ImGui::Checkbox(skCrypt("Timer [MB3]"), &timer);
					ImGui::Checkbox(skCrypt("Gravity"), &gravity);
					ImGui::Checkbox(skCrypt("Walk On Water [Z]"), &WalkOnWater);
					ImGui::Checkbox(skCrypt("Jump Shot"), &jumpshot);
					ImGui::Checkbox(skCrypt("Fly Bypass [X]"), &climb);	
					ImGui::Checkbox(skCrypt("Long Neck"), &longneck);
					ImGui::Checkbox(skCrypt("Speed Hack [MB4]"), &SPEEDhack);
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			ImGui::PopFont();
		}
		if (tab == 5)
		{
			ImGui::PushFont(main_font);
			{//left upper
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(15);
				ImGui::MenuChild(skCrypt("Values"), ImVec2(285, 415), false);
				{
					ImGui::SliderFloat(skCrypt("Gravity Distance"), &gravity_distancee, 1, 5, "% .2f");
					ImGui::SliderFloat(skCrypt("Fov Value"), &FOVV, 90, 150, "% .2f");
					ImGui::SliderFloat(skCrypt("Speed Value"), &speedBonus, 0, 1, "% .3f");
					ImGui::SliderFloat(skCrypt("FlyHack Speed Value"), &flyhackspeed, 0, 1, "% .3f");
					ImGui::SliderFloat(skCrypt("Timer Value"), &timervalue, 1, 8, "% .2f");
					ImGui::SliderFloat(skCrypt("Time Value"), &timee, 0, 24, "% .2f");
					ImGui::SliderFloat(skCrypt("Light Value"), &light, 0, 5, "% .2f");
					ImGui::SliderFloat(skCrypt("Crosshair Length"), &crosshair::sizes::cross::length, 1, 15, "% .2f");
                    ImGui::SliderFloat(skCrypt("Crosshair Gap"), &crosshair::sizes::cross::gap, 1, 15, "% .2f");
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			{//right
				ImGui::SetCursorPosY(50);
				ImGui::BeginGroup();
				ImGui::SetCursorPosX(320);
				ImGui::MenuChild(skCrypt("Config"), ImVec2(285, 415), false);
				{
					if (ImGui::Button(_xor_("Rage Config ").c_str())) { /*sayfa1*/ aimkey = VK_LBUTTON; silent = true; Predictionn = true; aimfovv = 90; sleeperignore = true; teamignoree = true; /*sayfa2*/ box = true; snapline = false; teamignore = true; name = true; healthbar = true; handweapon = true; sleeper = true; paintinside = true; weapons = true; playerinfoo = true; /*sayfa3*/ airdrop = true; minicopter = true; scrapheli = true; /*sayfa4*/ norecoil = true; nospread = true; fat_bullet_checkbox = true; full_automatic_checkbox = true; nosway = true; super_eoka_checkbox = true; supermeele = true; noshotgunspread = true; instantCompound = true; cross = true; instabow = true; spiderman = true; flyhack = true; timer = true; climb = true; /*sayfa5*/ spinbot = true; fov = true; alwaysday = true; FOVV = 110; WoundedAlert = true; showdistancee = true; showdistance = true; }
					if (ImGui::Button(_xor_("Legit Config").c_str())) { /*sayfa1*/  /*sayfa2*/ WoundedAlert = true; box = true; snapline = false; teamignore = true; name = true; healthbar = true; handweapon = true; sleeper = true; paintinside = true; weapons = true; playerinfoo = true; /*sayfa3*/ airdrop = true; minicopter = true; scrapheli = true; /*sayfa4*/ norecoil = true; full_automatic_checkbox = true; nosway = true; instantCompound = true; cross = true; instabow = true; spiderman = true;/*sayfa5*/ fov = true; alwaysday = true; FOVV = 110; showdistancee = true; showdistance = true; }
					if (ImGui::Button(_xor_("Zero Config").c_str())) { /*sayfa1*/ aimbot = false; silent = false; silentline = false; ssilent = false; Predictionn = false;  sleeperignore = false; teamignoree = false; woundedignore = false;/*sayfa2*/ box = false; snapline = false; name = false; box2 = false; healthbar = false; chams = false; skeleton = false; playercorpse = false; handweapon = false; backpack = false; sleeper = false; teamignore = false; playerinfoo = false; paintinside = false; wolf = false; bear = false; stag = false; chicken = false; boar = false; horse = false; weapons = false; showdistancee = false; showdistance = false; tunneldweller = false; scientistnpc = false; /*sayfa3*/ stone = false; stone2 = false; sulfur = false; sulfur2 = false; metal = false; metal2 = false; mushroom = false; hemp = false; military = false;  elite = false; loot = false; food = false; medical = false; toolbox = false; airdrop = false; stash = false; minicopter = false;  scrapheli = false; patrolheli = false; boat = false; rhib = false;  toolcupboard = false; autoturret = false; cars = false; /*sayfa4*/ norecoil = false; nospread = false; fat_bullet_checkbox = false; full_automatic_checkbox = false; nosway = false; super_eoka_checkbox = false; supermeele = false; noshotgunspread = false; instantCompound = false; zoom = false; ADS_Hide = false; cross = false; instabow = false; spiderman = false; flyhack = false; infinitejump = false; timer = false; gravity = false;  WalkOnWater = false; jumpshot = false;  climb = false; longneck = false;  SPEEDhack = false; /*sayfa5*/ admin_flag_checkboxx = false; fov = false; fakeworkbench = false; thirdperson = false; suicide = false;  alwaysday = false; nighttmode = false; AdminEsp = false;  fakelag = false;  spinbot = false; hardcoremodeMap = false;  WoundedAlert = false; }
				}
				ImGui::EndChild();
				ImGui::EndGroup();
			}
			ImGui::PopFont();
		}
	}
	ImGui::End();
}

void render()
{
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImVec2 curPos = ImGui::GetCursorPos();
	ImVec2 curWindowPos = ImGui::GetWindowPos();
	curPos.x += curWindowPos.x;
	curPos.y += curWindowPos.y;
	static float flRainbow;
	float flSpeed = 0.0025f;
	flRainbow += flSpeed;
	if (flRainbow > 1.f) flRainbow = 0.f;
	for (int i = 0; i < 485; i++)
	{
		float hue = (1.f / (float)485) * i;
		hue -= flRainbow;
		if (hue < 0.f) hue += 1.f;

		cRainbow = ImColor::HSV(hue, 1.f, 1.f);
		//ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(curPos.x + i, 10), ImVec2(curPos.x + 485, curPos.y - 3), cRainbow);
	}


	if (ssilent || psilent | aimbot | silent)
	{
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), aimfovv, IM_COL32_WHITE, 10000, 1);	
	}

	if (cross)
	{
		Crosshair();
	}
	//DrawString(16, (ScreenCenterX - 25), (ScreenCenterY + ScreenCenterY), &Col.red, true, false, LocalPlayer.BasePlayer->GetActiveWeaponText().c_str());
	if (ADS_Hide == true) {
		if (!GetAsyncKeyState(VK_RBUTTON))
		{
			cross = true;
		}
		else {
			cross = false;
		}
	}


	if (GetAsyncKeyState(g_menuKeyBind) & 1) { showmenu = !showmenu; }	

	

	draw();




	if (GetAsyncKeyState(VK_END) & 1) { exit(0); }

	if (showmenu) { draw_menu(); }

	ImGui::EndFrame();
	p_Device->SetRenderState(D3DRS_ZENABLE, false);
	p_Device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	p_Device->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	p_Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	if (p_Device->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		p_Device->EndScene();
	}

	HRESULT result = p_Device->Present(NULL, NULL, NULL, NULL);

	if (result == D3DERR_DEVICELOST && p_Device->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
	{
		ImGui_ImplDX9_InvalidateDeviceObjects();
		p_Device->Reset(&d3dpp);
		ImGui_ImplDX9_CreateDeviceObjects();
	}
}


namespace Util
{
	std::string RandomString(const int len);
	bool RenameFile(std::string& path);

}
std::string Util::RandomString(const int len)
{
	const std::string alpha_numeric(skCrypt("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890"));

	std::default_random_engine generator{ std::random_device{}() };
	const std::uniform_int_distribution< std::string::size_type > distribution{ 0, alpha_numeric.size() - 1 };

	std::string str(len, 0);
	for (auto& it : str)
		it = alpha_numeric[distribution(generator)];

	return str;
}

bool Util::RenameFile(std::string& path)
{
	std::string newPath = ("RUST CHEAT - " + Util::RandomString(16) + ".exe"); // generate a random string
	SetConsoleTitleA(Util::RandomString(16).c_str()); // set the console title to another random string

	if (std::rename(path.c_str(), newPath.c_str())) return false; // rename the file and return false if it failed

	path = newPath; // set the value of the path argument to the new path

	return true;
}

void AimbotTridi()
{
	while (true)
	{
		//auto baseMove = driver.read<uintptr_t>(Local_Player + oPlayerMovement); //baseplayer -> basemovement
		//driver.write<float>(baseMove + 0x40, 5000.f);
		for (auto Player : enemy_list)
		{
			if (AimFov(Player) < aimfovv)
			{
				aimbott(Player);
			}
		}
		//auto Movement = driver.read<uintptr_t>(Local_Player + oPlayerMovement);
		//float speed = (driver.read<bool>(Movement + 0x146) /*swim*/ || driver.read<float>(Movement + 0x44) /* ducking */ > 0.5f) ? 1.7f : (driver.read<bool>(Movement + 0x148) /*jump*/ ? 8.f : 5.5f);// playermovmen
		//Vector3 vel = driver.read<Vector3>(Movement + 0x34);
		//speed = max(speed, vel.Length());
		///*	if (settings::misc::always_sprint) {*/
		//float len = vel.Length();
		//if (len > 0.f) {
		//	vel = Vector3(vel.x / len * speed, vel.y, vel.z / len * speed);
		//	driver.write<Vector3>(Movement + 0x34, vel);
		//}	
		//modelstate->set_flag(rust::classes::ModelState_Flag::Sprinting);
		//driver.write<uintptr_t>(Local_Player + playerflags, 16);

//	}	
	/*	if (psilent)
		{
			for (auto Player : PatrolHeli)
			{
				if (AimFov(Player) < aimfovv)
				{
					pLocalPlayerHead = LocalPlayer.BasePlayer->Position2();
					pTargetBonePos = Player->Position3();
					Vector3 pTargetAngles = CalcAngle(pLocalPlayerHead, pTargetBonePos);
					Vector2 pAngles; pAngles.x = pTargetAngles.x, pAngles.y = pTargetAngles.y;


					pTargetBonePos = Prediction(pLocalPlayerHead, Player, BoneList(head), pTargetBonePos);



					if (GetAsyncKeyState(VK_LBUTTON)) {
						auto eyes = driver.read<uintptr_t>((uintptr_t)LocalPlayer.BasePlayer + oPlayerEyes);
						Vector4 pQuatAngles = ToQuat({ pAngles.x, pAngles.y, 0.0f });
						driver.write<Vector4>(eyes + 0x44, pQuatAngles);
					}
				}
			}
		}*/
		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

//enum console_color
//{
//	Black = 0,
//	Blue,
//	Green,
//	Cyan,
//	Red,
//	Magenta,
//	Brown,
//	LightGray,
//	DarkGray,
//	LightBlue,
//	LightGreen,
//	LightCyan,
//	LightRed,
//	LightMagenta,
//	Yellow,
//	White,
//};
//void set_color(const int forg_col)
//{
//	const auto h_std_out = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_SCREEN_BUFFER_INFO csbi;
//	if (GetConsoleScreenBufferInfo(h_std_out, &csbi))
//	{
//		const WORD w_color = (csbi.wAttributes & 0xF0) + (forg_col & 0x0F);
//		SetConsoleTextAttribute(h_std_out, w_color);
//	}
//}
//
//void set_text(const char* text, const int color)
//{
//	set_color(color);
//	printf(static_cast<const char*>(text));
//	set_color(White);
//}
//system(_xor_("cls").c_str());
//Sleep(1200);
//set_text(_xor_("Your license has been successfully activated").c_str(), Yellow);   BURASI ORNEK KISIM
//Sleep(5000);
//system(_xor_("cls").c_str());
//set_text(_xor_("Please Wait").c_str(), Yellow);


int main(int argCount, char** argVector)
{
	randomclassname2 = random_string(random_number(40, 50));
	/*std::string filePath = argVector[0];
	if (!Util::RenameFile(filePath))
	{
		Sleep(5000);
		return -1;
	}*/

	//if (driver.get_process_module("easyanticheat.sys") || driver.get_process_module("bedaisy.sys") || driver.get_process_module("vgk.sys"))
	//{
	//	ExRaiseStatus(STATUS_ABANDONED);
	//	ExRaiseAccessViolation();
	//	*(uint32_t*)0 = 0x13376969;
	//	return 0xBADC0DE;
	//}

	SetConsoleTitle(randomclassname.c_str());
	int horizontal = 0, vertical = 0;
	int x = 350, y = 250; //// alta doðru
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	SetConsoleCursorInfo(out, &cursorInfo);
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 15;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	system(skCrypt("color 4"));
	wcscpy_s(cfi.FaceName, skCrypt(L"Consolas"));
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	HWND hwnd = GetConsoleWindow();
	MoveWindow(hwnd, 0, 0, x, y, TRUE);
	LONG lStyle = GetWindowLong(hwnd, GWL_STYLE);
	lStyle &= ~(WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);
	SetWindowLong(hwnd, GWL_STYLE, lStyle);
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(console, &csbi);
	COORD scrollbar = {
		csbi.srWindow.Right - csbi.srWindow.Left + 1,
		csbi.srWindow.Bottom - csbi.srWindow.Top + 1
	};
	if (console == 0)
		throw 0;
	else
		SetConsoleScreenBufferSize(console, scrollbar);
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hwnd, 0, 225, LWA_ALPHA);
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);

	SetConsoleTitleA(randomclassname.c_str());
	mainprotect();

	std::string DosyaKonumu = (_xor_("C:\\Windows\\System\\RustPrivateLicense.txt"));

	KeyAuthApp.init();
	EnBasaDon:
	std::string License;
	FILE* Dosya;
	if (Dosya = fopen((DosyaKonumu.c_str()), skCrypt("r"))) {
		std::ifstream DosyaOku(DosyaKonumu.c_str());
		std::string Anahtar;	
		std::getline(DosyaOku, Anahtar);
		DosyaOku.close();
		fclose(Dosya);
		License = Anahtar;
		goto LisansaGit;
	}
	else
	{
		SetConsoleTitleA(skCrypt("  "));

		system(skCrypt("cls"));
		std::cout << skCrypt("\n\n  [+] Connecting..");
		std::cout << skCrypt("\n\n  [+] Enter License: ");
		std::cin >> License;
	LisansaGit:
		std::ofstream key; key.open(DosyaKonumu.c_str());
		key << License;
		key.close();
		KeyAuthApp.license(License);
		if (!KeyAuthApp.data.success)
		{
			std::cout << _xor_("\n Status: ").c_str() + KeyAuthApp.data.message;
			Sleep(1500);
			remove(DosyaKonumu.c_str());
			goto EnBasaDon;
			//exit(0);
		}
		system(skCrypt("cls"));
		Sleep(300);
		std::cout << skCrypt("\n\n  [+] License Activated.") << std::endl;;
	}

r8:
	if (!driver.init())
	{
	r7:
		if (FindWindowA(skCrypt("UnityWndClass"), NULL))
		{
			printf(skCrypt("[>] Close Rust...\n"));
			Sleep(1000);
			goto r7;	
		}
		if (LoadDriver())
		{
			printf(skCrypt("[>] Driver loaded!\n"));
			Sleep(1000);
			//system(skCrypt("cls"));
			goto r8;
		}
	}
	HWND Entryhwnd = NULL;
	while (Entryhwnd == NULL)
	{
		printf(skCrypt("[>] Open Rust\n"));
		Sleep(1);
		g_pid = get_pid();
		//printf(skCrypt("[>] pid: %d\n"), g_pid);
		Entryhwnd = get_process_wnd(g_pid);
		Sleep(1);
	}
	driver.attach(g_pid);
	setup_window();
	init_wndparams(MyWnd);
	g_assembly = driver.get_process_module(skCrypt("GameAssembly.dll"));
	g_unityplayer = driver.get_process_module(skCrypt("UnityPlayer.dll"));
	if (!g_assembly) { printf(skCrypt("[>] GameAssembly can't found!\n")); return 0; }
	if (!g_unityplayer) { printf(skCrypt("[>] UnityPlayer can't found\n")); return 0; }
	//printf("[>] GameAssembly: 0x%p\n[>] Unityplayer: 0x%p\n", g_assembly, g_unityplayer);
	::SetWindowPos(GetConsoleWindow(), HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_HIDEWINDOW);
	//std::thread(omni).detach();
	std::thread(Hilee).detach();
	std::thread(cheat).detach();
	std::thread(AimbotTridi).detach();
	static RECT old_rc;
	ZeroMemory(&Message, sizeof(MSG));	
	stylemenu2();
	//ImGui::StyleColorsDark();
	while (Message.message != WM_QUIT)
	{
		if (PeekMessage(&Message, MyWnd, 0, 0, PM_REMOVE)) {
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}

		HWND hwnd_active = GetForegroundWindow();


		if (hwnd_active == GameWnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(MyWnd, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}
		RECT rc;
		POINT xy;

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(GameWnd, &rc);
		ClientToScreen(GameWnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = GameWnd;
		io.DeltaTime = 1.0f / 60.0f;

		POINT p;
		GetCursorPos(&p);
		io.MousePos.x = p.x - xy.x;
		io.MousePos.y = p.y - xy.y;
		if (GetAsyncKeyState(0x1)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else io.MouseDown[0] = false;

		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom) {

			old_rc = rc;

			Width = rc.right;
			Height = rc.bottom;

			p_Params.BackBufferWidth = Width;
			p_Params.BackBufferHeight = Height;
			SetWindowPos(MyWnd, (HWND)0, xy.x, xy.y, Width, Height, SWP_NOREDRAW);
			p_Device->Reset(&p_Params);
		}
		render();
		Sleep(1);
	}

	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	cleanup_d3d();
	DestroyWindow(MyWnd);
	return Message.wParam;
}