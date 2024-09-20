- Composition implies ownership: the contained objects are created and owned by the containing class, and they are destroyed when the containing class is destroyed.
Destruction: Derived class -> Member Objects -> Base Class

- Aggregation (weak relationship) implies a shared or external relationship: the contained objects are not owned by the containing class.
Destruction: Derived class -> Member Objects (Owned Objects) -> Base Class 
Contained/Aggregated Objects should be deleted separately/manually

- Association (weaker relationship compared to composition and aggregation) 
When the class that holds the reference is destroyed, the associated objects are not destroyed unless explicitly handled.
Teacher & Student relationship.
