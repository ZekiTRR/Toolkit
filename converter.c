#include <stdio.h>
#include <ctype.h>

/* Function Prototypes */
 
void distance_converter(); 
void weight_converter();
void temperature_converter();
void data_storage_converter(); 

/* Main Hub Function
 *
 * This function displays a menu for the available converters and calls
 * the corresponding conversion function based on user selection.
 */
void hub()
{
    int hub_converter = 0;  // Variable to store the user's conversion type selection

    printf("%s\n", "Converter Hello!");
    printf("%s\n", "1. Distance converter");
    printf("%s\n", "2. Weight converter");
    printf("%s\n", "3. Temperature converter");
    printf("%s\n", "4. Data storage converter");
    
    // Read user's choice for the conversion type.
    scanf("%i", &hub_converter);

    /*
       User Selection Mapping:
         1 -> Distance conversion
         2 -> Weight conversion
         3 -> Temperature conversion (currently not implemented)
    */
    switch(hub_converter) {
        case 1:
            system("cls || clear");
            distance_converter();
            break;
        case 2:
            system("cls || clear");
            weight_converter();
            break;
        case 3:
            system("cls || clear");
            temperature_converter();
            break;
        case 4:
            system("cls || clear");
            data_storage_converter();
            break;
        default:
            // If the user's input does not match any case, print an error message.
            system("cls || clear");
            printf("%s\n\n\n", "Error expression!");
            break;
    }
}

/*
 * Function: distance_converter
 * Description:
 *   This function performs the conversion between various distance units.
 *   It follows these steps:
 *     1. Prompts the user to select a source unit from a predefined list.
 *     2. Reads the numeric value in the source unit.
 *     3. Prompts the user to select a target unit from the same list.
 *     4. Converts the given value first to meters (the base unit), then from meters
 *        to the target unit using an array of conversion factors.
 *     5. Displays the final converted value.
 */
void distance_converter() 
{ 
    int src_unit = 0;         // Stores the source unit option number
    int tgt_unit = 0;         // Stores the target unit option number
    double value = 0.0;       // Value in the source unit as entered by the user
    double value_in_meters = 0.0;   // Intermediate value converted to meters (base unit)
    double result = 0.0;      // Final conversion result in the target unit

    // Array of conversion factors from each unit to meters.
    // Mapping of indices:
    //   0: Placeholder
    //   1: Inch      -> 1 inch = 0.0254 meter
    //   2: Mil       -> 1 mil  = 0.0000254 meter (i.e., 1/1000 of an inch)
    //   3: Meter     -> 1 meter = 1.0 meter (base unit)
    //   4: Kilometer -> 1 kilometer = 1000 meters
    //   5: Foot      -> 1 foot = 0.3048 meter
    //   6: Yard      -> 1 yard = 0.9144 meter
    double factors[] = { 
        0.0,        // Placeholder for index 0
        0.0254,     // Inch to meter
        0.0000254,  // Mil to meter
        1.0,        // Meter (base unit)
        1000.0,     // Kilometer to meter
        0.3048,     // Foot to meter
        0.9144      // Yard to meter
    };

    // Display source unit options.
    printf("Select the source unit:\n");
    printf("1. Inch (in)\n");
    printf("2. Mil (mil)   // 1 mil = 1/1000 inch\n");
    printf("3. Meter (m)\n");
    printf("4. Kilometer (km)\n");
    printf("5. Foot (ft)\n");
    printf("6. Yard (yd)\n");

    // Prompt for the source unit selection.
    printf("Enter the number corresponding to the source unit: ");
    scanf("%d", &src_unit);

    // Validate that the source unit is within the valid range.
    if (src_unit < 1 || src_unit > 6) {
        printf("Invalid source unit selection.\n");
        return;
    }

    // Prompt the user to enter the value in the selected source unit.
    printf("Enter the value in the source unit: ");
    scanf("%lf", &value);

    // Display target unit options.
    printf("\nSelect the target unit:\n");
    printf("1. Inch (in)\n");
    printf("2. Mil (mil)\n");
    printf("3. Meter (m)\n");
    printf("4. Kilometer (km)\n");
    printf("5. Foot (ft)\n");
    printf("6. Yard (yd)\n");

    // Prompt for the target unit selection.
    printf("Enter the number corresponding to the target unit: ");
    scanf("%d", &tgt_unit);

    // Validate that the target unit is within the valid range.
    if (tgt_unit < 1 || tgt_unit > 6) {
        printf("Invalid target unit selection.\n\n\n");
        return;
    }

    // Convert the input value to the base unit (meters).
    value_in_meters = value * factors[src_unit];

    // Convert the intermediate value in meters to the target unit.
    result = value_in_meters / factors[tgt_unit];

    // Display the final conversion result.
    printf("%.6lf\n\n\n", result);
}

/*
 * Function: weight_converter
 * Description:
 *   This function is intended for weight unit conversion.
 *   It defines an array of conversion factors to convert various weight units to the
 *   base unit (grams). The mapping in the array is as follows:
 *      index 0: Placeholder
 *      index 1: Milligram -> 1 mg = 0.001 gram
 *      index 2: Kilogram  -> 1 kg = 1000 grams
 *      index 3: Ton       -> 1 ton = 1,000,000 grams
 *      index 4: Centner   -> 1 centner = 100,000 grams
 *      index 5: Karat     -> 1 karat = 0.2 gram
 *      index 6: British Pound -> 1 British pound ≈ 453.59 grams
 *
 *   Note: This function is currently a placeholder and only prints a test message.
 */
void weight_converter()
{
    int src_unit = 0;
    int tgt_unit = 0;
    double value = 0.0;       // Value in the source unit as entered by the user
    double value_in_grams  = 0.0;   // Intermediate value converted to grams (base unit)
    double result = 0.0;      // Final conversion result in the target unit


    double weight_factors[] = {
        0.0,      // Placeholder for index 0
        0.001,    // Milligram to gram
        1000,     // Kilogram to gram
        1000000,  // Ton to gram
        100000,   // Centner to gram
        0.2,      // Karat to gram
        453.59    // British Pound to gram
    };

    // Future implementation will handle:
    //   - Prompting the user to select source and target weight units.
    //   - Reading the weight value and performing the conversion using weight_factors.
//    printf("%s\n", "Test");
    printf("Enter the weight unit and quantity (e.g., 'kg 50' for 50 kilograms). Available units:\n"
    "1. Milligram (mg): 1 milligram = 0.001 gram\n"
   // "2. Gram (g): The base unit; no conversion needed\n"
    "2. Kilogram (kg): 1 kilogram = 1000 grams\n"
    "3. Ton (t): 1 ton = 1,000,000 grams\n"
    "4. Centner (cen): 1 centner = 100,000 grams\n"
    "5. Karat (k): 1 karat = 0.2 gram\n"
    "6. British Pound (lb): 1 British pound ?= 453.59 grams\n");

    scanf("%d", &src_unit);

    printf("%s\n", "Enter the value: ");
    scanf("%lf", &value);


    printf("%s", "Enter the target unit: ");
    scanf("%d", &tgt_unit);
    
    // printf("%s%d%d%d\n","The src,value,tgt: " ,src_unit,value,tgt_unit);

    value_in_grams = value *  weight_factors[src_unit];
    // printf("%.2f\n", value_in_grams);
    result = value_in_grams / weight_factors[tgt_unit];
    printf("%.6lf\n\n\n", result);

}


/*
 * Function: temperature_converter
 * Description:
 *   This function converts temperatures between three popular units:
 *     1. Celsius (°C)
 *     2. Fahrenheit (°F)
 *     3. Kelvin (K)
 *
 *   Steps:
 *     1. Prompts the user to select a source temperature unit.
 *     2. Reads the temperature value in the chosen source unit.
 *     3. Prompts the user to select a target temperature unit.
 *     4. Converts the input value first to Celsius (the base unit), then from Celsius
 *        to the target unit using standard formulas.
 *     5. Displays the final converted temperature.
 */
void temperature_converter() 
{
    int src_unit = 0;             // Stores the selected source temperature unit
    int tgt_unit = 0;             // Stores the selected target temperature unit
    double value = 0.0;           // Temperature value in the source unit
    double result = 0.0;          // Final conversion result in the target unit
    double value_in_celsius = 0.0; // Intermediate temperature in Celsius (base unit)

    // Display source temperature unit options.
    printf("Select the source temperature unit:\n");
    printf("1. Celsius (oC)\n");
    printf("2. Fahrenheit (oF)\n");
    printf("3. Kelvin (K)\n");

    // Prompt for the source unit selection.
    printf("Enter the number corresponding to the source unit: ");
    scanf("%d", &src_unit);

    // Validate the source unit selection.
    if (src_unit < 1 || src_unit > 3) 
    {
        printf("Invalid source temperature unit selection.\n");
        return;
    }

    // Prompt the user to enter the temperature value.
    printf("Enter the temperature value: ");
    scanf("%lf", &value);

    // Display target temperature unit options.
    printf("\nSelect the target temperature unit:\n");
    printf("1. Celsius (oC)\n");
    printf("2. Fahrenheit (oF)\n");
    printf("3. Kelvin (K)\n");

    // Prompt for the target unit selection.
    printf("Enter the number corresponding to the target unit: ");
    scanf("%d", &tgt_unit);

    // Validate the target unit selection.
    if (tgt_unit < 1 || tgt_unit > 3) 
    {
        printf("Invalid target temperature unit selection.\n");
        return;
    }

    // Convert the input temperature to Celsius (base unit).
    switch (src_unit) 
    {
        case 1: // Celsius (°C)
            value_in_celsius = value;
            break;
        case 2: // Fahrenheit (°F) to Celsius: C = (F - 32) * 5/9
            value_in_celsius = (value - 32.0) * (5.0 / 9.0);
            break;
        case 3: // Kelvin (K) to Celsius: C = K - 273.15
            value_in_celsius = value - 273.15;
            break;
    }

    // Convert the Celsius value to the target temperature unit.
    switch (tgt_unit) 
    {
        case 1: // Celsius (°C)
            result = value_in_celsius;
            break;
        case 2: // Fahrenheit (°F): F = C * 9/5 + 32
            result = value_in_celsius * (9.0 / 5.0) + 32.0;
            break;
        case 3: // Kelvin (K): K = C + 273.15
            result = value_in_celsius + 273.15;
            break;
    }

    // Display the final conversion result.
    printf("Converted temperature: %.2lf\n\n", result);
}

void data_storage_converter() 
{
    int src_unit = 0;             // Stores the selected source unit
    int tgt_unit = 0;             // Stores the selected target unit
    double value = 0.0;           // Input value in source unit
    double result = 0.0;          // Final result in target unit
    double value_in_bytes = 0.0;  // Intermediate value in Bytes (base unit)

    // Display source unit options
    printf("Select the source storage unit:\n");
    printf("1. Bytes (B)\n");
    printf("2. Kilobytes (KB)\n");
    printf("3. Megabytes (MB)\n");
    printf("4. Gigabytes (GB)\n");
    printf("5. Terabytes (TB)\n");

    // Prompt for source unit selection
    printf("Enter the number corresponding to the source unit: ");
    scanf("%d", &src_unit);

    // Validate source unit
    if (src_unit < 1 || src_unit > 5) 
    {
        printf("Invalid source storage unit selection.\n");
        return;
    }

    // Prompt for the storage value
    printf("Enter the storage value: ");
    scanf("%lf", &value);

    // Display target unit options
    printf("\nSelect the target storage unit:\n");
    printf("1. Bytes (B)\n");
    printf("2. Kilobytes (KB)\n");
    printf("3. Megabytes (MB)\n");
    printf("4. Gigabytes (GB)\n");
    printf("5. Terabytes (TB)\n");

    // Prompt for target unit selection
    printf("Enter the number corresponding to the target unit: ");
    scanf("%d", &tgt_unit);

    // Validate target unit
    if (tgt_unit < 1 || tgt_unit > 5) 
    {
        printf("Invalid target storage unit selection.\n");
        return;
    }

    // Convert source unit to Bytes (base unit)
    switch (src_unit) 
    {
        case 1: // Bytes (B)
            value_in_bytes = value;
            break;
        case 2: // Kilobytes (KB) to Bytes
            value_in_bytes = value * 1024.0;
            break;
        case 3: // Megabytes (MB) to Bytes
            value_in_bytes = value * 1024.0 * 1024.0;
            break;
        case 4: // Gigabytes (GB) to Bytes
            value_in_bytes = value * 1024.0 * 1024.0 * 1024.0;
            break;
        case 5: // Terabytes (TB) to Bytes
            value_in_bytes = value * 1024.0 * 1024.0 * 1024.0 * 1024.0;
            break;
    }

    // Convert Bytes to target unit
    switch (tgt_unit) 
    {
        case 1: // Bytes (B)
            result = value_in_bytes;
            break;
        case 2: // Bytes to Kilobytes (KB)
            result = value_in_bytes / 1024.0;
            break;
        case 3: // Bytes to Megabytes (MB)
            result = value_in_bytes / (1024.0 * 1024.0);
            break;
        case 4: // Bytes to Gigabytes (GB)
            result = value_in_bytes / (1024.0 * 1024.0 * 1024.0);
            break;
        case 5: // Bytes to Terabytes (TB)
            result = value_in_bytes / (1024.0 * 1024.0 * 1024.0 * 1024.0);
            break;
    }

    // Display the final conversion result
    system("cls || clear");
    printf("Converted storage: %.2lf\n\n", result);
}