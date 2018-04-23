# RKDlib
Knihovna v jazyce C++ pro řízení modelového kolejiště Mendelu
## Models & tools
K modelování používáme AsciiDoctor a AsciiDoctor-Diagram
### Jak na Asciidoctor
* Instalace
	- [Ruby](https://rubyinstaller.org/)
	- [AsciiDoctor](http://asciidoctor.org/#installation)
	- [AsciiDoctor-Diagram](http://asciidoctor.org/docs/asciidoctor-diagram/#installation)
* Kopilace: `$ asciidoctor -r asciidoctor-diagram sample.adoc`
* AsciiDoctor user guide: [http://asciidoctor.org/docs/user-manual/](http://asciidoctor.org/docs/user-manual/)
* PlantUML user guide: [http://plantuml.com/](http://plantuml.com/)
### Příklad
```
= Component diagram
Blah blah ...

== Diagram
[plantuml, "Component-diagram", png]
....
class Access
class EEprom
class UART
class GeneralHelper
class OpsShot
....
```
## Github Preview
pro zobrazení diagramů v html můžete použít Github Preview
[https://htmlpreview.github.io/](https://htmlpreview.github.io/)

Konkrétní modely
* [Základní model](https://htmlpreview.github.io/?https://github.com/LANeo64/RKDlib/blob/master/Model/Diagrams.html)