#include <stdio.h>
#include <ctype.h>

/*
Converters:
    Distance:

 * - Inch (in): 1 m ≈ 39.37007874 inches.
 * - Mil (mil): 1 mil = 1/1000 of an inch. Thus, 1 m ≈ 39.37007874 * 1000 mil.
 * - Meter (m): The base unit (value remains unchanged).
 * - Kilometer (km): 1 km = 1000 m.
 * - Foot (ft): 1 m ≈ 3.280839895 feet.
 * - Yard (yd): 1 m ≈ 1.093613298 yards.
    Base -> meters
*/


void hub()
{
    printf("%s\n", "Converter Hello!");
    printf("%s\n", "1. Distance converter");
    printf("%s\n", "2. Mass converter");
    printf("%s\n", "3. Temperature converter");
}

void distance_converter() {
    int src_unit = 0;         // Variable to store the source unit option
    int tgt_unit = 0;         // Variable to store the target unit option
    double value = 0.0;       // The value in the source unit entered by the user
    double value_in_meters = 0.0;   // Intermediate value converted to meters
    double result = 0.0;      // Final conversion result in the target unit

    // Conversion factors to convert each unit to meters.
    // Using an array where index mapping is as follows:
    // Index 1: Inch  => 1 inch = 0.0254 meter
    // Index 2: Mil   => 1 mil  = 0.0254 / 1000 = 0.0000254 meter
    // Index 3: Meter => 1 meter = 1.0 meter
    // Index 4: Kilometer => 1 kilometer = 1000 meters
    // Index 5: Foot  => 1 foot = 0.3048 meter
    // Index 6: Yard  => 1 yard = 0.9144 meter
    double factors[] = { 
        0.0,        // Placeholder for index 0
        0.0254,     // Inch to meter
        0.0000254,  // Mil to meter
        1.0,        // Meter to meter
        1000.0,     // Kilometer to meter
        0.3048,     // Foot to meter
        0.9144      // Yard to meter
    };

    // Print source unit options
    printf("Select the source unit:\n");
    printf("1. Inch (in)\n");
    printf("2. Mil (mil)   // 1 mil = 1/1000 inch\n");
    printf("3. Meter (m)\n");
    printf("4. Kilometer (km)\n");
    printf("5. Foot (ft)\n");
    printf("6. Yard (yd)\n");

    // Get user input for the source unit
    printf("Enter the number corresponding to the source unit: ");
    scanf("%d", &src_unit);

    if (src_unit < 1 || src_unit > 6) {
        printf("Invalid source unit selection.\n");
        return;
    }

    // Get the value in the source unit from the user
    printf("Enter the value in the source unit: ");
    scanf("%lf", &value);

    // Print target unit options
    printf("\nSelect the target unit:\n");
    printf("1. Inch (in)\n");
    printf("2. Mil (mil)\n");
    printf("3. Meter (m)\n");
    printf("4. Kilometer (km)\n");
    printf("5. Foot (ft)\n");
    printf("6. Yard (yd)\n");

    // Get user input for the target unit
    printf("Enter the number corresponding to the target unit: ");
    scanf("%d", &tgt_unit);

    if (tgt_unit < 1 || tgt_unit > 6) {
        printf("Invalid target unit selection.\n\n\n");
        return;
    }

    // Convert the value in the source unit to meters
    value_in_meters = value * factors[src_unit];

    // Convert the value in meters to the target unit
    result = value_in_meters / factors[tgt_unit];

    // Display the result, showing the conversion from the source value to the target unit
    printf("%.6lf\n\n\n", result);

}