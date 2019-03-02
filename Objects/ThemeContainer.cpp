#include "ThemeContainer.h"
#include "../Objects/INIReader.h"
#include <sstream>

namespace ed
{
	std::string ThemeContainer::LoadTheme(const std::string& filename)
	{
		static const std::string ColorNames[] = {
			"Text",
			"TextDisabled",
			"WindowBg",
			"ChildBg",
			"PopupBg",
			"Border",
			"BorderShadow",
			"FrameBg",
			"FrameBgHovered",
			"FrameBgActive",
			"TitleBg",
			"TitleBgActive",
			"TitleBgCollapsed",
			"MenuBarBg",
			"ScrollbarBg",
			"ScrollbarGrab",
			"ScrollbarGrabHovered",
			"ScrollbarGrabActive",
			"CheckMark",
			"SliderGrab",
			"SliderGrabActive",
			"Button",
			"ButtonHovered",
			"ButtonActive",
			"Header",
			"HeaderHovered",
			"HeaderActive",
			"Separator",
			"SeparatorHovered",
			"SeparatorActive",
			"ResizeGrip",
			"ResizeGripHovered",
			"ResizeGripActive",
			"Tab",
			"TabHovered",
			"TabActive",
			"TabUnfocused",
			"TabUnfocusedActive",
			"DockingPreview",
			"DockingEmptyBg",
			"PlotLines",
			"PlotLinesHovered",
			"PlotHistogram",
			"PlotHistogramHovered",
			"TextSelectedBg",
			"DragDropTarget",
			"NavHighlight",
			"NavWindowingHighlight",
			"NavWindowingDimBg",
			"ModalWindowDimBg"
		};

		INIReader ini("./themes/" + filename);
		
		std::string name = ini.Get("general", "name", "NULL");

		ImGuiStyle& style = m_ui[name];
		ImGuiStyle& defaultStyle = ImGui::GetStyle();
		TextEditor::Palette& palette = m_editor[name];

		for (int i = 0; i < ImGuiCol_COUNT; i++) {
			std::string clr = ini.Get("colors", ColorNames[i], "0");
			if (clr == "0")
				style.Colors[(ImGuiCol_)i] = defaultStyle.Colors[(ImGuiCol_)i];
			else
				style.Colors[(ImGuiCol_)i] = m_parseColor(clr);
		}

		style.Alpha = ini.GetReal("style", "Alpha", defaultStyle.Alpha);
		style.WindowPadding.x = ini.GetReal("style", "WindowPaddingX", defaultStyle.WindowPadding.x);
		style.WindowPadding.y = ini.GetReal("style", "WindowPaddingY", defaultStyle.WindowPadding.y);
		style.WindowRounding = ini.GetReal("style", "WindowRounding", defaultStyle.WindowRounding);
		style.WindowBorderSize = ini.GetReal("style", "WindowBorderSize", defaultStyle.WindowBorderSize);
		style.WindowMinSize.x = ini.GetReal("style", "WindowMinSizeX", defaultStyle.WindowMinSize.x);
		style.WindowMinSize.y = ini.GetReal("style", "WindowMinSizeY", defaultStyle.WindowMinSize.y);
		style.WindowTitleAlign.x = ini.GetReal("style", "WindowTitleAlignX", defaultStyle.WindowTitleAlign.x);
		style.WindowTitleAlign.y = ini.GetReal("style", "WindowTitleAlignY", defaultStyle.WindowTitleAlign.y);
		style.ChildRounding = ini.GetReal("style", "ChildRounding", defaultStyle.ChildRounding);
		style.ChildBorderSize = ini.GetReal("style", "ChildBorderSize", defaultStyle.ChildBorderSize);
		style.PopupRounding = ini.GetReal("style", "PopupRounding", defaultStyle.PopupRounding);
		style.PopupBorderSize = ini.GetReal("style", "PopupBorderSize", defaultStyle.PopupBorderSize);
		style.FramePadding.x = ini.GetReal("style", "FramePaddingX", defaultStyle.FramePadding.x);
		style.FramePadding.y = ini.GetReal("style", "FramePaddingY", defaultStyle.FramePadding.y);
		style.FrameRounding = ini.GetReal("style", "FrameRounding", defaultStyle.FrameRounding);
		style.FrameBorderSize = ini.GetReal("style", "FrameBorderSize", defaultStyle.FrameBorderSize);
		style.ItemSpacing.x = ini.GetReal("style", "ItemSpacingX", defaultStyle.ItemSpacing.x);
		style.ItemSpacing.y = ini.GetReal("style", "ItemSpacingY", defaultStyle.ItemSpacing.y);
		style.ItemInnerSpacing.x = ini.GetReal("style", "ItemInnerSpacingX", defaultStyle.ItemInnerSpacing.x);
		style.ItemInnerSpacing.y = ini.GetReal("style", "ItemInnerSpacingY", defaultStyle.ItemInnerSpacing.y);
		style.TouchExtraPadding.x = ini.GetReal("style", "TouchExtraPaddingX", defaultStyle.TouchExtraPadding.x);
		style.TouchExtraPadding.y = ini.GetReal("style", "TouchExtraPaddingY", defaultStyle.TouchExtraPadding.y);
		style.IndentSpacing = ini.GetReal("style", "IndentSpacing", defaultStyle.IndentSpacing);
		style.ColumnsMinSpacing = ini.GetReal("style", "ColumnsMinSpacing", defaultStyle.ColumnsMinSpacing);
		style.ScrollbarSize = ini.GetReal("style", "ScrollbarSize", defaultStyle.ScrollbarSize);
		style.ScrollbarRounding = ini.GetReal("style", "ScrollbarRounding", defaultStyle.ScrollbarRounding);
		style.GrabMinSize = ini.GetReal("style", "GrabMinSize", defaultStyle.GrabMinSize);
		style.GrabRounding = ini.GetReal("style", "GrabRounding", defaultStyle.GrabRounding);
		style.TabRounding = ini.GetReal("style", "TabRounding", defaultStyle.TabRounding);
		style.TabBorderSize = ini.GetReal("style", "TabBorderSize", defaultStyle.TabBorderSize);
		style.ButtonTextAlign.x = ini.GetReal("style", "ButtonTextAlignX", defaultStyle.ButtonTextAlign.x);
		style.ButtonTextAlign.y = ini.GetReal("style", "ButtonTextAlignY", defaultStyle.ButtonTextAlign.y);
		style.DisplayWindowPadding.x = ini.GetReal("style", "DisplayWindowPaddingX", defaultStyle.DisplayWindowPadding.x);
		style.DisplayWindowPadding.y = ini.GetReal("style", "DisplayWindowPaddingY", defaultStyle.DisplayWindowPadding.y);
		style.DisplaySafeAreaPadding.x = ini.GetReal("style", "DisplaySafeAreaPaddingX", defaultStyle.DisplaySafeAreaPadding.x);
		style.DisplaySafeAreaPadding.y = ini.GetReal("style", "DisplaySafeAreaPaddingY", defaultStyle.DisplaySafeAreaPadding.y);
		style.MouseCursorScale = ini.GetReal("style", "MouseCursorScale", defaultStyle.MouseCursorScale);
		style.AntiAliasedLines = ini.GetBoolean("style", "AntiAliasedLines", defaultStyle.AntiAliasedLines);
		style.AntiAliasedFill = ini.GetBoolean("style", "AntiAliasedFill", defaultStyle.AntiAliasedFill);
		style.CurveTessellationTol = ini.GetReal("style", "CurveTessellationTol", defaultStyle.CurveTessellationTol);

		if (ini.Get("general", "editor", "Dark") == "Custom") {
			/* TODO: LOAD TEXT EDITOR PALETTE */
		}

		return name;
	}
	ImGuiStyle ThemeContainer::GetUIStyle(const std::string& name)
	{
		return m_ui[name];
	}
	TextEditor::Palette ThemeContainer::GetTextEditorStyle(const std::string& name)
	{
		return m_editor[name];
	}
	ImVec4 ThemeContainer::m_parseColor(const std::string& str)
	{
		float res[4] = { 0,0,0,0 };
		int cur = 0;

		std::stringstream ss(str);
		while(ss.good())
		{
			std::string substr;
			std::getline(ss, substr, ',');
			res[cur] = std::stof(substr);

			cur++;
		}

		return ImVec4(res[0], res[1], res[2], res[3]);
	}
}