#define SEVIIAN_FORM 0

const u8 *gRegionalSymbols[] =
{
    [SEVIIAN_FORM] = gText_SeviiFormSymbol
};

#define FORM_SPECIES_INDEX(formSpecies) ((formSpecies) - NUM_NON_FORM_MON_SPRITES)
#define ORIGIN_REGION(formSpecies, regionalForm) [FORM_SPECIES_INDEX(formSpecies)] = (regionalForm)

const u8 gFormMonOriginRegion[NUM_FORMS] =
{
    ORIGIN_REGION(SPECIES_FOSSILIZED_KABUTOPS, SEVIIAN_FORM),
    ORIGIN_REGION(SPECIES_SEVIIAN_AERODACTYL, SEVIIAN_FORM)
};
