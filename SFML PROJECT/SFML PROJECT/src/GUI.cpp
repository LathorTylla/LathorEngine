#include "GUI.h"
#include "Window.h"
#include "Actor.h"
#include "transform.h"
#include "Services/NotificationSystem.h"


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

  // Definici�n de colores ne�n
  ImVec4 neonPink = ImVec4(1.0f, 0.07f, 0.58f, 1.0f);
  ImVec4 neonBlue = ImVec4(0.0f, 0.5f, 1.0f, 1.0f);
  ImVec4 neonGreen = ImVec4(0.0f, 1.0f, 0.5f, 1.0f);
  ImVec4 backgroundColor = ImVec4(0.05f, 0.05f, 0.1f, 1.0f);
  ImVec4 activeGlow = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);

  // Asignaci�n de colores a diferentes elementos
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

  // Texto en color verde ne�n para la consola
  ImGui::GetStyle().Colors[ImGuiCol_Text] = neonGreen;

  // Ajuste de tama�o para fuentes y objetos
  ImGui::GetStyle().ScaleAllSizes(1.2f); // Incrementar el tama�o ligeramente
}

void
GUI::console(const std::map<ConsolErrorType, std::vector<std::string>>& programMessages) {
  ImGui::Begin("Console"); 
  static ImGuiTextFilter filter; // Filtro de b�squeda
  filter.Draw("Filter (\"error\", \"warning\", etc.)", 180.0f);
  ImGui::Separator();
  ImGui::BeginChild("ScrollingRegion", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);
  for (const auto& pair : programMessages) {
    // Establece color seg�n el tipo de mensaje
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
      color = ImVec4(0.8f, 0.8f, 0.8f, 1.0f); // Gris para mensajes de informaci�n
      break;
    }
    for (const auto& message : pair.second) {
      if (!filter.PassFilter(message.c_str())) continue; // Filtrar mensajes seg�n el filtro de b�squeda
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

void GUI::hierarchy(const std::vector<EngineUtilities::TSharedPointer<Actor>>& actors, int& selectedActorID) {
  ImGui::Begin("Hierarchy"); // Abrir la ventana de jerarqu�a


  for (int i = 0; i < actors.size(); ++i) {
    if (!actors[i].isNull()) {
      if (ImGui::Selectable(actors[i]->getName().c_str(), selectedActorID == i)) {
        selectedActorID = i;  // Establecer actor seleccionado
      }
    }
  }

  ImGui::End(); // Cerrar la ventana de jerarqu�a
}

void GUI::inspector(EngineUtilities::TSharedPointer<Actor> selectedActor) {
  if (selectedActor.isNull()) return;

  ImGui::Begin("Inspector"); // Abrir la ventana de Inspector

  ImGui::Text("Actor: %s", selectedActor->getName().c_str());

  auto transform = selectedActor->getComponent<Transform>();
  if (!transform.isNull()) {
    sf::Vector2f position = transform->getPosition();
    sf::Vector2f scale = transform->getScale();

    // Mostrar y editar posici�n
    if (ImGui::InputFloat2("Position", reinterpret_cast<float*>(&position))) {
      transform->setPosition(position);
    }

    // Mostrar y editar escala
    if (ImGui::InputFloat2("Scale", reinterpret_cast<float*>(&scale))) {
      transform->setScale(scale);
    }

  }

  ImGui::End(); // Cerrar la ventana de Inspector
}

void GUI::actorCreationMenu(std::vector<EngineUtilities::TSharedPointer<Actor>>& actors) {
  static char actorName[128] = "";  // Para almacenar el nombre del actor temporalmente
  static int selectedShape = 0;     // 0: Rect�ngulo, 1: C�rculo, 2: Tri�ngulo

  ImGui::Begin("Actor Creation");

  ImGui::InputText("Actor Name", actorName, IM_ARRAYSIZE(actorName));
  ImGui::Combo("Shape", &selectedShape, "Rectangle\0Circle\0Triangle\0");

  if (ImGui::Button("Create Actor")) {
    std::string name = actorName;

    if (name.empty()) {
      // Enviar mensaje de error si el nombre est� vac�o
      NotificationService& notifier = NotificationService::getInstance();
      notifier.addMessage(ConsolErrorType::ERROR, "Actor creation failed: Actor name cannot be empty.");
    }
    else {
      // Crear el actor con el nombre y forma seleccionada
      EngineUtilities::TSharedPointer<Actor> newActor = EngineUtilities::MakeShared<Actor>(name);

      switch (selectedShape) {
      case 0:
        newActor->getComponent<ShapeFactory>()->createShape(ShapeType::RECTANGLE);
        break;
      case 1:
        newActor->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);
        break;
      case 2:
        newActor->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
        break;
      }

      // Agregar el nuevo actor al vector de actores
      actors.push_back(newActor);

      // Notificar �xito en la creaci�n
      NotificationService& notifier = NotificationService::getInstance();
      notifier.addMessage(ConsolErrorType::INF, "Actor '" + name + "' created successfully.");

      // Limpiar el campo de nombre para el pr�ximo actor
      actorName[0] = '\0';
    }
  }
  ImGui::End();
}


