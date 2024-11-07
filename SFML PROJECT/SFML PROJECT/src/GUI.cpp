#include "GUI.h"
#include "Window.h"

void 
GUI::init() {

  //Setup GUI style
  setupGUIStye();
}

void 
GUI::update() {

}

void 
GUI::render() {

}

void
GUI::destroy() {
}

void 
GUI::setupGUIStye() {

  ImGui::StyleColorsClassic();

  ImGuiStyle& style = ImGui::GetStyle();
  style.WindowRounding = 5.3f;
  style.FrameRounding = 4.0f;
  style.ScrollbarRounding = 5.0f;
  style.GrabRounding = 3.0f;
  style.TabRounding = 3.0f;
  style.WindowPadding = ImVec2(10, 10);
  style.FramePadding = ImVec2(5, 5);
  style.ItemSpacing = ImVec2(8, 8);
  style.ItemInnerSpacing = ImVec2(5, 5);

  // Definición de colores neón
  ImVec4 neonPink = ImVec4(1.0f, 0.07f, 0.58f, 1.0f);
  ImVec4 neonBlue = ImVec4(0.0f, 0.5f, 1.0f, 1.0f);
  ImVec4 neonGreen = ImVec4(0.0f, 1.0f, 0.5f, 1.0f);
  ImVec4 backgroundColor = ImVec4(0.05f, 0.05f, 0.1f, 1.0f);
  ImVec4 activeGlow = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);

  // Asignación de colores a diferentes elementos
  ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = backgroundColor;
  ImGui::GetStyle().Colors[ImGuiCol_TitleBgActive] = neonPink;
  ImGui::GetStyle().Colors[ImGuiCol_TitleBg] = backgroundColor;
  ImGui::GetStyle().Colors[ImGuiCol_Border] = neonPink;
  ImGui::GetStyle().Colors[ImGuiCol_FrameBg] = ImVec4(0.2f, 0.2f, 0.24f, 1.0f);
  ImGui::GetStyle().Colors[ImGuiCol_FrameBgHovered] = neonBlue;
  ImGui::GetStyle().Colors[ImGuiCol_FrameBgActive] = neonGreen;
  ImGui::GetStyle().Colors[ImGuiCol_Button] = neonPink;
  ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered] = neonBlue;
  ImGui::GetStyle().Colors[ImGuiCol_ButtonActive] = activeGlow;
  ImGui::GetStyle().Colors[ImGuiCol_Header] = neonGreen;
  ImGui::GetStyle().Colors[ImGuiCol_HeaderHovered] = neonBlue;
  ImGui::GetStyle().Colors[ImGuiCol_HeaderActive] = neonPink;

  // Texto en color verde neón para la consola
  ImGui::GetStyle().Colors[ImGuiCol_Text] = neonGreen;

  // Ajuste de tamaño para fuentes y objetos
  ImGui::GetStyle().ScaleAllSizes(1.2f); // Incrementar el tamaño ligeramente
}

void
GUI::console(std::map<ConsolErrorType, std::string> programMessages) {
  ImGui::Begin("Console");
  for (const auto& pair : programMessages) {
    ImGui::Text("Code: %d - Message: %s", pair.first, pair.second.c_str());
  }
  ImGui::End();
}