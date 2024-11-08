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
GUI::console(const std::map<ConsolErrorType, std::vector<std::string>>& programMessages) {
  ImGui::Begin("Console"); 
  static ImGuiTextFilter filter; // Filtro de búsqueda
  filter.Draw("Filter (\"error\", \"warning\", etc.)", 180.0f);
  ImGui::Separator();
  ImGui::BeginChild("ScrollingRegion", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);
  for (const auto& pair : programMessages) {
    // Establece color según el tipo de mensaje
    ImVec4 color;
    switch (pair.first) {
    case ConsolErrorType::ERROR:
      color = ImVec4(1.0f, 0.4f, 0.4f, 1.0f); // Rojo para errores
      break;
    case ConsolErrorType::WARNING:
      color = ImVec4(1.0f, 1.0f, 0.4f, 1.0f); // Amarillo para advertencias
      break;
    case ConsolErrorType::INF:
    default:
      color = ImVec4(0.8f, 0.8f, 0.8f, 1.0f); // Gris para mensajes de información
      break;
    }
    for (const auto& message : pair.second) {
      if (!filter.PassFilter(message.c_str())) continue; // Filtrar mensajes según el filtro de búsqueda
      ImGui::PushStyleColor(ImGuiCol_Text, color);
      ImGui::Text("[%d] %s", pair.first, message.c_str());
      ImGui::PopStyleColor();
    }
  }
  if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
  ImGui::SetScrollHereY(1.0f);
  ImGui::EndChild();
  ImGui::End();
}