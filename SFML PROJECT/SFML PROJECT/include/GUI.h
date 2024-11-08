#pragma once
#include "Prerequisites.h"
#include <vector>
#include "Actor.h"

class Window;

class 
GUI {
public:
	GUI() = default;
	~GUI() = default;

  void
  init();

  
  void
  update();

  
  void
  render();

  void
  destroy();

	void 
  setupGUIStye();

  void
  console(const std::map<ConsolErrorType, std::vector<std::string>>& programMessages);

  void 
  hierarchy(const std::vector<EngineUtilities::TSharedPointer<Actor>>& actors, int& selectedActorID);

  void 
  actorCreationMenu(std::vector<EngineUtilities::TSharedPointer<Actor>>& actors);


  void 
  inspector(EngineUtilities::TSharedPointer<Actor> selectedActor);




private:
  std::map<int, std::string> m_programMessages;
};

