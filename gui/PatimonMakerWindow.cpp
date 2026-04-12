#include "PatimonMakerWindow.h"

#include <imgui.h>

#include <vector>

PatimonMakerWindow::PatimonMakerWindow() :
    rarity(0),
    piece(0),
    set(0),
    tier(0),
    substat1(0),
    substat2(0),
    substat3(0),
    msg(),
    onSendGear(),
    currentOperation()
{
}

void ShowVectorCombo(const std::vector<const char*>& v, const char *name, int& index) {
    if (ImGui::BeginCombo(name, v[index], 0)) {
        for (int i = 0; i < (int)v.size(); ++i) {
            bool is_selected = index == i;
            if (ImGui::Selectable(v[i], is_selected)) {
                index = i;
            }
        }
        ImGui::EndCombo();
    }
}

void ShowSubstatCombo(const char *name, int& index) {
    const std::vector<const char *> substats = {
        "None",
        "Maximum HP I", "Maximum HP I+", "Maximum HP II", "Maximum HP II+",
        "Maximum HP III", "Maximum HP III+", "Maximum HP IV", "Maximum HP IV+", "Maximum HP IV++",
        "Attack I", "Attack I+", "Attack II", "Attack II+",
        "Attack III", "Attack III+", "Attack IV", "Attack IV+", "Attack IV++",
        "Defense I", "Defense I+", "Defense II", "Defense II+",
        "Defense III", "Defense III+", "Defense IV", "Defense IV+", "Defense IV++",
        "Support I", "Support I+", "Support II", "Support II+",
        "Support III", "Support III+", "Support IV", "Support IV+", "Support IV++",
        "Critical Rate I", "Critical Rate I+", "Critical Rate II", "Critical Rate II+",
        "Critical Rate III", "Critical Rate III+", "Critical Rate IV", "Critical Rate IV+", "Critical Rate IV++",
        "Critical DMG Multiplier I", "Critical DMG Multiplier I+", "Critical DMG Multiplier II",
        "Critical DMG Multiplier II+", "Critical DMG Multiplier III", "Critical DMG Multiplier III+",
        "Critical DMG Multiplier IV", "Critical DMG Multiplier IV+", "Critical DMG Multiplier IV++",
        "Moving Speed I", "Moving Speed II", "Moving Speed III", "Moving Speed IV",
        "Grant Recovery Effect I", "Grant Recovery Effect I+", "Grant Recovery Effect II",
        "Grant Recovery Effect II+", "Grant Recovery Effect III", "Grant Recovery Effect III+",
        "Grant Recovery Effect IV", "Grant Recovery Effect IV+", "Grant Recovery Effect IV++",
        "Maximum Stamina I", "Maximum Stamina II", "Maximum Stamina III", "Maximum Stamina IV",
        "Damage Cut Rate", "Damage Cut Rate+", "Damage Cut Rate++",
        "Shield Resistance I", "Shield Resistance II", "Shield Resistance III", "Shield Resistance IV",
        "Shield Damage Reduction I", "Shield Damage Reduction II",
        "Shield Damage Reduction III", "Shield Damage Reduction IV",
        "Counterattack Stamina Cost Reduction I", "Counterattack Stamina Cost Reduction II",
        "Counterattack Stamina Cost Reduction III", "Counterattack Stamina Cost Reduction IV",
        "Ultimate Skill Efficiency I", "Ultimate Skill Efficiency II",
        "Ultimate Skill Efficiency III", "Ultimate Skill Efficiency IV",
        "Life Absorption", "Life Absorption+",
        "Regenerate", "Regenerate+",
        "Shield Expansion", "Shield Expansion+",
        "Of Sword and Spear", "Of Sword and Spear+",
        "Backstab", "Backstab+",
        "Ninja Footwork",
        "Line Drive Enhanced", "Hitting Stride Enhanced", "Grand Slam Enhanced", "Pinch Hitter Enhanced",
        "Iroha Starter Enhanced", "Iroha Ball: Δ Enhanced", "Iroha Ball: Ω Enhanced", "Winning Pitch Enhanced",
        "Toxic Amplifier Enhanced", "Toxic Smash Enhanced", "Serum Explosion Enhanced", "Swift Elimination Enhanced",
        "Luminous Amplifier Enhanced", "Vertical Crystal Enhanced", "Resonance Accelerator Enhanced",
        "Radiant Slay Enhanced",
        "The Beast Enhanced", "Time to Eat! Enhanced", "Behave! Enhanced", "Support Command SO-1 Enhanced",
        "Choreography Enhanced", "Glorious Stage Enhanced", "Heated Fury Enhanced", "Unstoppable! Enhanced",
        "Full Speed Ahead Enhanced", "Iron Fist Justice Enhanced", "Importance of Reading Enhanced",
        "Finishing Touch Enhanced", "Invigorating Surge Enhanced", "Dusk's Whispers Enhanced",
        "Billionaire Law Enhanced", "Spotlight Enhanced", "Golden Cross Enhanced", "Dynamo Smasher Enhanced",
        "Roar of Outrage Enhanced", "Exhaust Boost Enhanced", "Barbacoa Blade Enhanced", "Grill Impact Enhanced",
        "Ignition Enhanced", "Well-Done Smash Enhanced", "Misteltein Δ Enhanced", "Extensive Enhanced",
        "Full Commitment Enhanced", "Outbound Marketing Enhanced", "Subtle Swing Enhanced",
        "Declaration Enhanced", "Broken Moral Enhanced", "Crimson Enhanced", "The Sly Serpent Enhanced",
        "Deflect Server Enhanced", "Overclock Enhanced", "Redeploy Enhanced", "Masamune Glove Enhanced",
        "Magic Pitch No. 1 - Phantom Enhanced", "Magic Pitch No. 3 - Abyss Enhanced", "Wild Pitch Enhanced",
        "Toad Tekka​maru Enhanced", "Toad Shot Enhanced", "Akiba Ninjutsu: Manifestation Enhanced",
        "Akiba Ninjutsu: Pursuit Enhanced", "Iron Fist of Doom III Enhanced", "Akiba Kenjutsu: Lovely Impact Enhanced",
        "Akiba Kenjutsu: Rocket Punch! Enhanced", "Wings of A Craftsman Enhanced", "Akiba Eaglejutsu: AXL Enhanced",
        "Akiba Eaglejutsu: CHN Enhanced"
    };

    ShowVectorCombo(substats, name, index);
}

void PatimonMakerWindow::ShowTiersCombo() {
    const std::vector<const char *> tiers = {
        "Tier 1", "Tier 2", "Tier 3", 
        "Tier 4", "Tier 5", "Tier 6",
        "Tier 7", "Tier 8", "Tier 9",
        "Tier 11"
    };

    ShowVectorCombo(tiers, "Tier", tier);
}

void PatimonMakerWindow::ShowSetsCombo() {
    const std::vector<const char *> sets = {
        "Attacker", "Gladiator", "Berserker",
        "Defender", "Paladin", "Fortress",
        "Healer", "Trickster", "Enchanter",
    };

    ShowVectorCombo(sets, "Set", set);
}

void PatimonMakerWindow::Show(bool* p_open) {
    if (ImGui::Begin("Patimon Maker", p_open, 0)) {
        if (currentOperation.valid()) {
            if (auto status = currentOperation.wait_for(std::chrono::milliseconds(0)); status == std::future_status::ready) {
                auto result = currentOperation.get();
                if (!result.first) {
                    msg = "Patimon sended to mails!!";
                } else {
                    msg = "Error: " + result.second;
                }
            } else {
                msg = "Sending to mails...";
            }
        }

        ImGui::Text("Msg: %s", msg.c_str());

        ImGui::Combo("Rarity", &rarity, "Gray Rarity\0Blue Rarity\0Purple Rarity\0Gold Rarity\0\0");
        ImGui::Combo("Piece", &piece, "Head\0Body\0Other\0\0");
        ShowSetsCombo();
        ShowTiersCombo();
        ShowSubstatCombo("1st Substat", substat1);
        ShowSubstatCombo("2nd Substat", substat2);
        ShowSubstatCombo("3rd Substat", substat3);

        ImGui::BeginDisabled(currentOperation.valid());

        if (ImGui::Button("Send gear to mails") && onSendGear) {
            currentOperation = std::async(std::launch::async,
                onSendGear, rarity, piece, set, tier, substat1, substat2, substat3
            );
        }

        ImGui::EndDisabled();
    }

    ImGui::End();
}