/*
 * Unit Test Bootstrap
 * Autor: Tomasz Jaworski, 2018-2020
 *
 * Test dla zadania Projekt: czytnik dysku, woluminu, katalogu głównego i plików (3,0)
 * Autor testowanej odpowiedzi: Przemysław Dudek
 * Test wygenerowano automatycznie o 2023-01-13 16:21:12.563213
 *
 * Debug: 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <setjmp.h>
#include <assert.h>

#if !defined(__clang__) && !defined(__GNUC__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na swoim kompilatorze C.
#error System testow jednostkowych jest przeznaczony dla kompilatorów GCC/Clang.
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na platformie Windows.
#error System testow jednostkowych NIE jest przeznaczony dla testów uruchamianych na platformach Windows.
#endif

#define _RLDEBUG_API_
#include "unit_helper_v2.h"
#include "rdebug.h"

#include "tested_declarations.h"
#include "rdebug.h"

//
// Elementy globalne dla całego testu
//




//
//  Test 1: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST1(void)
{
    // informacje o teście
    test_start(1, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("CENTER.TX");
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 2: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST2(void)
{
    // informacje o teście
    test_start(2, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file(NULL);
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 3: Sprawdzanie poprawności działania funkcji disk_close
//
void UTEST3(void)
{
    // informacje o teście
    test_start(3, "Sprawdzanie poprawności działania funkcji disk_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            disk_close(NULL);
      
            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 4: Sprawdzanie poprawności działania funkcji fat_open
//
void UTEST4(void)
{
    // informacje o teście
    test_start(4, "Sprawdzanie poprawności działania funkcji fat_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("prove.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 5: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST5(void)
{
    // informacje o teście
    test_start(5, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct volume_t* volume = fat_open(NULL, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 6: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST6(void)
{
    // informacje o teście
    test_start(6, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(10240, 1);
                char expected_filecontent[10241] = "";
        
                strcat(expected_filecontent, "s Beatrice?\"--\"See her,\" she replied,\n\"Beneath the fresh leaf seated on its root.\nBehold th\' associate choir that circles her.\nThe others, with a melody more sweet\nAnd more profound, journeying to higher realms,\nUpon the Gryphon tend.\"  If there her words\nWere clos\'d, I know not; but mine eyes had now\nTa\'en view of her, by whom all other thoughts\nWere barr\'d admittance.  On the very ground\nAlone she sat, as she had there been left\nA guard upon the wain, which I beheld\nBound to the twyform beast.  The seven nymphs\nDid make themselves a cloister round about her,\nAnd in their hands upheld those lights secure\nFrom blast septentrion and the gusty south.\n     \"A little while thou shalt be forester here:\nAnd citizen shalt be forever with me,\nOf that true Rome, wherein Christ dwells a Roman\nTo profit the misguided world, keep now\nThine eyes upon the car; and what thou seest,\nTake heed thou write, returning to that place.\"\n     Thus Beatrice: at whose feet inclin\'d\nDevout, at her behest, my thought and eyes,\nI, as she bade, directed.  Never fire,\nWith so swift motion, forth a stormy cloud\nLeap\'d downward from the welkin\'s farthest bound,\nAs I beheld the bird of Jove descending\nPounce on the tree, and, as he rush\'d, the rind,\nDisparting crush beneath him, buds much more\nAnd leaflets.  On the car with all his might\nHe struck, whence, staggering like a ship, it reel\'d,\nAt random driv\'n, to starboard now, o\'ercome,\nAnd now to larboard, by the vaulting waves.\n     Next springing up into the chariot\'s womb\nA fox I saw, with hunger seeming pin\'d\nOf all good food.  But, for his ugly sins\nThe saintly maid rebuking him, away\nScamp\'ring he turn\'d, fast as his hide-bound corpse\nWould bear him.  Next, from whence before he came,\nI saw the eagle dart into the hull\nO\' th\' car, and leave it with his feathers lin\'d;\nAnd then a voice, like that which issues forth\nFrom heart with sorrow riv\'d, did issue forth\nFrom heav\'n, and, \"O poor bark of mine!\" it cried,\n\"How badly art thou freighted!\"  Then, it seem\'d,\nThat the earth open\'d between either wheel,\nAnd I beheld a dragon issue thence,\nThat through the chariot fix\'d his forked train;\nAnd like a wasp that draggeth back the sting,\nSo drawing forth his baleful train, he dragg\'d\nPart of the bottom forth, and went his way\nExulting.  What remain\'d, as lively turf\nWith green herb, so did clothe itself with plumes,\nWhich haply had with purpose chaste and kind\nBeen offer\'d; and therewith were cloth\'d the wheels,\nBoth one and other, and the beam, so quickly\nA sigh were not breath\'d sooner.  Thus transform\'d,\nThe holy structure, through its several parts,\nDid put forth heads, three on the beam, and one\nOn every side; the first like oxen horn\'d,\nBut with a single horn upon their front\nThe four.  Like monster sight hath never seen.\nO\'er it methought there sat, secure as rock\nOn mountain\'s lofty top, a shameless whore,\nWhose ken rov\'d loosely round her.  At her side,\nAs \'t were that none might bear her off, I saw\nA giant stand; and ever, and anon\nThey mingled kisses.  But, her lustful eyes\nChancing on me to wander, that fell minion\nScourg\'d her from head to foot all o\'er; then full\nOf jealousy, and fierce with rage, unloos\'d\nThe monster, and dragg\'d on, so far across\nThe forest, that from me its shades alone\nShielded the harlot and the new-form\'d brute.\n\n\n\nCANTO XXXIII\n\n\"The heathen, Lord!  are come!\" responsive thus,\nThe trinal now, and now the virgin band\nQuaternion, their sweet psalmody began,\nWeeping; and Beatrice listen\'d, sad\nAnd sighing, to the song\', in such a mood,\nThat Mary, as she stood beside the cross,\nWas scarce more chang\'d.  But when they gave her place\nTo speak, then, risen upright on her feet,\nShe, with a colour glowing bright as fire,\nDid answer: \"Yet a little while, and ye\nShall see me not; and, my beloved sisters,\nAgain a little while, and ye shall see me.\"\n     Before her then she marshall\'d all the seven,\nAnd, beck\'ning only motion\'d me, the dame,\nAnd that remaining sage, to follow her.\n     So on she pass\'d; and had not set, I ween,\nHer tenth step to the ground, when with mine eyes\nHer ");
    strcat(expected_filecontent, "eyes encounter\'d; and, with visage mild,\n\"So mend thy pace,\" she cried, \"that if my words\nAddress thee, thou mayst still be aptly plac\'d\nTo hear them.\"  Soon as duly to her side\nI now had hasten\'d:  \"Brother!\" she began,\n\"Why mak\'st thou no attempt at questioning,\nAs thus we walk together?\"  Like to those\nWho, speaking with too reverent an awe\nBefore their betters, draw not forth the voice\nAlive unto their lips, befell me shell\nThat I in sounds imperfect thus began:\n\"Lady!  what I have need of, that thou know\'st,\nAnd what will suit my need.\"  She answering thus:\n\"Of fearfulness and shame, I will, that thou\nHenceforth do rid thee: that thou speak no more,\nAs one who dreams.  Thus far be taught of me:\nThe vessel, which thou saw\'st the serpent break,\nWas and is not: let him, who hath the blame,\nHope not to scare God\'s vengeance with a sop.\nWithout an heir for ever shall not be\nThat eagle, he, who left the chariot plum\'d,\nWhich monster made it first and next a prey.\nPlainly I view, and therefore speak, the stars\nE\'en now approaching, whose conjunction, free\nFrom all impediment and bar, brings on\nA season, in the which, one sent from God,\n(Five hundred, five, and ten, do mark him out)\nThat foul one, and th\' accomplice of her guilt,\nThe giant, both shall slay.  And if perchance\nMy saying, dark as Themis or as Sphinx,\nFail to persuade thee, (since like them it foils\nThe intellect with blindness) yet ere long\nEvents shall be the Naiads, that will solve\nThis knotty riddle, and no damage light\nOn flock or field.  Take heed; and as these words\nBy me are utter\'d, teach them even so\nTo those who live that life, which is a race\nTo death: and when thou writ\'st them, keep in mind\nNot to conceal how thou hast seen the plant,\nThat twice hath now been spoil\'d.  This whoso robs,\nThis whoso plucks, with blasphemy of deed\nSins against God, who for his use alone\nCreating hallow\'d it.  For taste of this,\nIn pain and in desire, five thousand years\nAnd upward, the first soul did yearn for him,\nWho punish\'d in himself the fatal gust.\n     \"Thy reason slumbers, if it deem this height\nAnd summit thus inverted of the plant,\nWithout due cause: and were not vainer thoughts,\nAs Elsa\'s numbing waters, to thy soul,\nAnd their fond pleasures had not dyed it dark\nAs Pyramus the mulberry, thou hadst seen,\nIn such momentous circumstance alone,\nGod\'s equal justice morally implied\nIn the forbidden tree.  But since I mark thee\nIn understanding harden\'d into stone,\nAnd, to that hardness, spotted too and stain\'d,\nSo that thine eye is dazzled at my word,\nI will, that, if not written, yet at least\nPainted thou take it in thee, for the cause,\nThat one brings home his staff inwreath\'d with palm.\n     \"I thus:  \"As wax by seal, that changeth not\nIts impress, now is stamp\'d my brain by thee.\nBut wherefore soars thy wish\'d-for speech so high\nBeyond my sight, that loses it the more,\nThe more it strains to reach it?\" --\"To the end\nThat thou mayst know,\" she answer\'d straight, \"the school,\nThat thou hast follow\'d; and how far behind,\nWhen following my discourse, its learning halts:\nAnd mayst behold your art, from the divine\nAs distant, as the disagreement is\n\'Twixt earth and heaven\'s most high and rapturous orb.\"\n     \"I not remember,\" I replied, \"that e\'er\nI was estrang\'d from thee, nor for such fault\nDoth conscience chide me.\"  Smiling she return\'d:\n\"If thou canst, not remember, call to mind\nHow lately thou hast drunk of Lethe\'s wave;\nAnd, sure as smoke doth indicate a flame,\nIn that forgetfulness itself conclude\nBlame from thy alienated will incurr\'d.\nFrom henceforth verily my words shall be\nAs naked as will suit them to appear\nIn thy unpractis\'d view.\"  More sparkling now,\nAnd with retarded course the sun possess\'d\nThe circle of mid-day, that varies still\nAs th\' aspect varies of each several clime,\nWhen, as one, sent in vaward of a troop\nFor escort, pauses, if perchance he spy\nVestige of somewhat strange and rare: so paus\'d\nThe sev\'nfold band, arriving at the verge\nOf a dun umbrage hoar, such as is seen,\nBeneath green leaves and gloomy branches, oft\nTo overbrow a bleak ");
    strcat(expected_filecontent, "and alpine cliff.\nAnd, where they stood, before them, as it seem\'d,\nTigris and Euphrates both beheld,\nForth from one fountain issue; and, like friends,\nLinger at parting. \"O enlight\'ning beam!\nO glory of our kind!  beseech thee say\nWhat water this, which from one source deriv\'d\nItself removes to distance from itself?\"\n     To such entreaty answer thus was made:\n\"Entreat Matilda, that she teach thee this.\"\n     And here, as one, who clears himself of blame\nImputed, the fair dame return\'d:  \"Of me\nHe this and more hath learnt; and I am safe\nThat Lethe\'s water hath not hid it from him.\"\n     And Beatrice:  \"Some more pressing care\nThat oft the memory \'reeves, perchance hath made\nHis mind\'s eye dark.  But lo!  where Eunoe cows!\nLead thither; and, as thou art wont, revive\nHis fainting virtue.\"  As a courteous spirit,\nThat proffers no excuses, but as soon\nAs he hath token of another\'s will,\nMakes it his own; when she had ta\'en me, thus\nThe lovely maiden mov\'d her on, and call\'d\nTo Statius with an air most lady-like:\n\"Come thou with him.\"  Were further space allow\'d,\nThen, Reader, might I sing, though but in part,\nThat beverage, with whose sweetness I had ne\'er\nBeen sated.  But, since all the leaves are full,\nAppointed for this second strain, mine art\nWith warning bridle checks me.  I return\'d\nFrom the most holy wave, regenerate,\nIf \'en as new plants renew\'d with foliage new,\nPure and made apt for mounting to the stars.\n\n\n\nNOTES TO PURGATORY\n\nCANTO I\n\nVerse 1.  O\'er better waves.]  Berni, Orl. Inn. L 2. c. i.\nPer correr maggior acqua alza le vele,\nO debil navicella del mio ingegno.\n\nv. 11.  Birds of chattering note.]  For the fable of the\ndaughters of Pierus, who challenged the muses to sing, and were\nby them\nchanged into magpies, see Ovid, Met. 1. v. fab. 5.\n\nv. 19.  Planet.]  Venus.\n\nv. 20.  Made all the orient laugh.]  Hence Chaucer, Knight\'s\nTale: And all the orisont laugheth of the sight.\n\nIt is sometimes read \"orient.\"\n\nv. 24.  Four stars.]  Symbolical of the four cardinal virtues,\nPrudence Justice, Fortitude, and T");
                
        
                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "LIKE.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 10240, file);
                test_error(size == 10240, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 10240 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 10240);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 10240);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 7: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST7(void)
{
    // informacje o teście
    test_start(7, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(13248, 1);
                char expected_filecontent[13249] = "";
        
                strcat(expected_filecontent, ", if chance a passing cloud\nSo sail across, that opposite it hangs,\nSuch then Antaeus seem\'d, as at mine ease\nI mark\'d him stooping.  I were fain at times\nT\' have pass\'d another way.  Yet in th\' abyss,\nThat Lucifer with Judas low ingulfs,\nI,ightly he plac\'d us; nor there leaning stay\'d,\nBut rose as in a bark the stately mast.\n\n\n\nCANTO XXXII\n\nCOULD I command rough rhimes and hoarse, to suit\nThat hole of sorrow, o\'er which ev\'ry rock\nHis firm abutment rears, then might the vein\nOf fancy rise full springing:  but not mine\nSuch measures, and with falt\'ring awe I touch\nThe mighty theme; for to describe the depth\nOf all the universe, is no emprize\nTo jest with, and demands a tongue not us\'d\nTo infant babbling.  But let them assist\nMy song, the tuneful maidens, by whose aid\nAmphion wall\'d in Thebes, so with the truth\nMy speech shall best accord.  Oh ill-starr\'d folk,\nBeyond all others wretched!  who abide\nIn such a mansion, as scarce thought finds words\nTo speak of, better had ye here on earth\nBeen flocks or mountain goats.  As down we stood\nIn the dark pit beneath the giants\' feet,\nBut lower far than they, and I did gaze\nStill on the lofty battlement, a voice\nBespoke me thus:  \"Look how thou walkest.  Take\nGood heed, thy soles do tread not on the heads\nOf thy poor brethren.\"  Thereupon I turn\'d,\nAnd saw before and underneath my feet\nA lake, whose frozen surface liker seem\'d\nTo glass than water.  Not so thick a veil\nIn winter e\'er hath Austrian Danube spread\nO\'er his still course, nor Tanais far remote\nUnder the chilling sky.  Roll\'d o\'er that mass\nHad Tabernich or Pietrapana fall\'n,\nNot e\'en its rim had creak\'d. As peeps the frog\nCroaking above the wave, what time in dreams\nThe village gleaner oft pursues her toil,\nSo, to where modest shame appears, thus low\nBlue pinch\'d and shrin\'d in ice the spirits stood,\nMoving their teeth in shrill note like the stork.\nHis face each downward held; their mouth the cold,\nTheir eyes express\'d the dolour of their heart.\n     A space I look\'d around, then at my feet\nSaw two so strictly join\'d, that of their head\nThe very hairs were mingled.  \"Tell me ye,\nWhose bosoms thus together press,\" said I,\n\"Who are ye?\"  At that sound their necks they bent,\nAnd when their looks were lifted up to me,\nStraightway their eyes, before all moist within,\nDistill\'d upon their lips, and the frost bound\nThe tears betwixt those orbs and held them there.\nPlank unto plank hath never cramp clos\'d up\nSo stoutly.  Whence like two enraged goats\nThey clash\'d together; them such fury seiz\'d.\n     And one, from whom the cold both ears had reft,\nExclaim\'d, still looking downward: \"Why on us\nDost speculate so long?  If thou wouldst know\nWho are these two, the valley, whence his wave\nBisenzio slopes, did for its master own\nTheir sire Alberto, and next him themselves.\nThey from one body issued; and throughout\nCaina thou mayst search, nor find a shade\nMore worthy in congealment to be fix\'d,\nNot him, whose breast and shadow Arthur\'s land\nAt that one blow dissever\'d, not Focaccia,\nNo not this spirit, whose o\'erjutting head\nObstructs my onward view:  he bore the name\nOf Mascheroni:  Tuscan if thou be,\nWell knowest who he was:  and to cut short\nAll further question, in my form behold\nWhat once was Camiccione.  I await\nCarlino here my kinsman, whose deep guilt\nShall wash out mine.\"  A thousand visages\nThen mark\'d I, which the keen and eager cold\nHad shap\'d into a doggish grin; whence creeps\nA shiv\'ring horror o\'er me, at the thought\nOf those frore shallows.  While we journey\'d on\nToward the middle, at whose point unites\nAll heavy substance, and I trembling went\nThrough that eternal chillness, I know not\nIf will it were or destiny, or chance,\nBut, passing \'midst the heads, my foot did strike\nWith violent blow against the face of one.\n     \"Wherefore dost bruise me?\" weeping, he exclaim\'d,\n\"Unless thy errand be some fresh revenge\nFor Montaperto, wherefore troublest me?\"\n     I thus:  \"Instructor, now await me here,\nThat I through him may rid me of my doubt.\nThenceforth what haste thou wilt.\"  The teacher paus\'d,\nAnd to that shade I s");
    strcat(expected_filecontent, "pake, who bitterly\nStill curs\'d me in his wrath.  \"What art thou, speak,\nThat railest thus on others?\"  He replied:\n\"Now who art thou, that smiting others\' cheeks\nThrough Antenora roamest, with such force\nAs were past suff\'rance, wert thou living still?\"\n     \"And I am living, to thy joy perchance,\"\nWas my reply, \"if fame be dear to thee,\nThat with the rest I may thy name enrol.\"\n     \"The contrary of what I covet most,\"\nSaid he, \"thou tender\'st:  hence; nor vex me more.\nIll knowest thou to flatter in this vale.\"\n     Then seizing on his hinder scalp, I cried:\n\"Name thee, or not a hair shall tarry here.\"\n     \"Rend all away,\" he answer\'d, \"yet for that\nI will not tell nor show thee who I am,\nThough at my head thou pluck a thousand times.\"\n     Now I had grasp\'d his tresses, and stript off\nMore than one tuft, he barking, with his eyes\nDrawn in and downward, when another cried,\n\"What ails thee, Bocca?  Sound not loud enough\nThy chatt\'ring teeth, but thou must bark outright?\nWhat devil wrings thee?\"--\" Now,\" said I, \"be dumb,\nAccursed traitor!  to thy shame of thee\nTrue tidings will I bear.\"--\" Off,\" he replied,\n\"Tell what thou list; but as thou escape from hence\nTo speak of him whose tongue hath been so glib,\nForget not:  here he wails the Frenchman\'s gold.\n\'Him of Duera,\' thou canst say, \'I mark\'d,\nWhere the starv\'d sinners pine.\'  If thou be ask\'d\nWhat other shade was with them, at thy side\nIs Beccaria, whose red gorge distain\'d\nThe biting axe of Florence.  Farther on,\nIf I misdeem not, Soldanieri bides,\nWith Ganellon, and Tribaldello, him\nWho op\'d Faenza when the people slept.\"\n     We now had left him, passing on our way,\nWhen I beheld two spirits by the ice\nPent in one hollow, that the head of one\nWas cowl unto the other; and as bread\nIs raven\'d up through hunger, th\' uppermost\nDid so apply his fangs to th\' other\'s brain,\nWhere the spine joins it.  Not more furiously\nOn Menalippus\' temples Tydeus gnaw\'d,\nThan on that skull and on its garbage he.\n     \"O thou who show\'st so beastly sign of hate\n\'Gainst him thou prey\'st on, let me hear,\" said I\n\"The cause, on such condition, that if right\nWarrant thy grievance, knowing who ye are,\nAnd what the colour of his sinning was,\nI may repay thee in the world above,\nIf that, wherewith I speak be moist so long.\"\n\n\n\nCANTO XXXIII\n\nHIS jaws uplifting from their fell repast,\nThat sinner wip\'d them on the hairs o\' th\' head,\nWhich he behind had mangled, then began:\n\"Thy will obeying, I call up afresh\nSorrow past cure, which but to think of wrings\nMy heart, or ere I tell on\'t. But if words,\nThat I may utter, shall prove seed to bear\nFruit of eternal infamy to him,\nThe traitor whom I gnaw at, thou at once\nShalt see me speak and weep.  Who thou mayst be\nI know not, nor how here below art come:\nBut Florentine thou seemest of a truth,\nWhen I do hear thee.  Know I was on earth\nCount Ugolino, and th\' Archbishop he\nRuggieri.  Why I neighbour him so close,\nNow list.  That through effect of his ill thoughts\nIn him my trust reposing, I was ta\'en\nAnd after murder\'d, need is not I tell.\nWhat therefore thou canst not have heard, that is,\nHow cruel was the murder, shalt thou hear,\nAnd know if he have wrong\'d me.  A small grate\nWithin that mew, which for my sake the name\nOf famine bears, where others yet must pine,\nAlready through its opening sev\'ral moons\nHad shown me, when I slept the evil sleep,\nThat from the future tore the curtain off.\nThis one, methought, as master of the sport,\nRode forth to chase the gaunt wolf and his whelps\nUnto the mountain, which forbids the sight\nOf Lucca to the Pisan.  With lean brachs\nInquisitive and keen, before him rang\'d\nLanfranchi with Sismondi and Gualandi.\nAfter short course the father and the sons\nSeem\'d tir\'d and lagging, and methought I saw\nThe sharp tusks gore their sides.  When I awoke\nBefore the dawn, amid their sleep I heard\nMy sons (for they were with me) weep and ask\nFor bread.  Right cruel art thou, if no pang\nThou feel at thinking what my heart foretold;\nAnd if not now, why use thy tears to flow?\nNow had they waken\'d; and the hour drew near\nWhen they we");
    strcat(expected_filecontent, "re wont to bring us food; the mind\nOf each misgave him through his dream, and I\nHeard, at its outlet underneath lock\'d up\nThe\' horrible tower:  whence uttering not a word\nI look\'d upon the visage of my sons.\nI wept not:  so all stone I felt within.\nThey wept:  and one, my little Anslem, cried:\n\"Thou lookest so!  Father what ails thee?\"  Yet\nI shed no tear, nor answer\'d all that day\nNor the next night, until another sun\nCame out upon the world.  When a faint beam\nHad to our doleful prison made its way,\nAnd in four countenances I descry\'d\nThe image of my own, on either hand\nThrough agony I bit, and they who thought\nI did it through desire of feeding, rose\nO\' th\' sudden, and cried, \'Father, we should grieve\nFar less, if thou wouldst eat of us: thou gav\'st\nThese weeds of miserable flesh we wear,\nAnd do thou strip them off from us again.\'\nThen, not to make them sadder, I kept down\nMy spirit in stillness.  That day and the next\nWe all were silent.  Ah, obdurate earth!\nWhy open\'dst not upon us?  When we came\nTo the fourth day, then Geddo at my feet\nOutstretch\'d did fling him, crying, \'Hast no help\nFor me, my father!\'  \"There he died, and e\'en\nPlainly as thou seest me, saw I the three\nFall one by one \'twixt the fifth day and sixth:\nWhence I betook me now grown blind to grope\nOver them all, and for three days aloud\nCall\'d on them who were dead.  Then fasting got\nThe mastery of grief.\"  Thus having spoke,\nOnce more upon the wretched skull his teeth\nHe fasten\'d, like a mastiff\'s \'gainst the bone\nFirm and unyielding.  Oh thou Pisa!  shame\nOf all the people, who their dwelling make\nIn that fair region, where th\' Italian voice\nIs heard, since that thy neighbours are so slack\nTo punish, from their deep foundations rise\nCapraia and Gorgona, and dam up\nThe mouth of Arno, that each soul in thee\nMay perish in the waters!  What if fame\nReported that thy castles were betray\'d\nBy Ugolino, yet no right hadst thou\nTo stretch his children on the rack.  For them,\nBrigata, Ugaccione, and the pair\nOf gentle ones, of whom my song hath told,\nTheir tender years, thou modern Thebes!  did make\nUncapable of guilt.  Onward we pass\'d,\nWhere others skarf\'d in rugged folds of ice\nNot on their feet were turn\'d, but each revers\'d\n     There very weeping suffers not to weep;\nFor at their eyes grief seeking passage finds\nImpediment, and rolling inward turns\nFor increase of sharp anguish:  the first tears\nHang cluster\'d, and like crystal vizors show,\nUnder the socket brimming all the cup.\n     Now though the cold had from my face dislodg\'d\nEach feeling, as \'t were callous, yet me seem\'d\nSome breath of wind I felt.  \"Whence cometh this,\"\nSaid I, \"my master?  Is not here below\nAll vapour quench\'d?\"--\"\'Thou shalt be speedily,\"\nHe answer\'d, \"where thine eye shall tell thee whence\nThe cause descrying of this airy shower.\"\n     Then cried out one in the chill crust who mourn\'d:\n\"O souls so cruel!  that the farthest post\nHath been assign\'d you, from this face remove\nThe harden\'d veil, that I may vent the grief\nImpregnate at my heart, some little space\nEre it congeal again!\"  I thus replied:\n\"Say who thou wast, if thou wouldst have mine aid;\nAnd if I extricate thee not, far down\nAs to the lowest ice may I descend!\"\n     \"The friar Alberigo,\" answered he,\n\"Am I, who from the evil garden pluck\'d\nIts fruitage, and am here repaid, the date\nMore luscious for my fig.\"--\"Hah!\"  I exclaim\'d,\n\"Art thou too dead!\"--\"How in the world aloft\nIt fareth with my body,\" answer\'d he,\n\"I am right ignorant.  Such privilege\nHath Ptolomea, that ofttimes the soul\nDrops hither, ere by Atropos divorc\'d.\nAnd that thou mayst wipe out more willingly\nThe glazed tear-drops that o\'erlay mine eyes,\nKnow that the soul, that moment she betrays,\nAs I did, yields her body to a fiend\nWho after moves and governs it at will,\nTill all its time be rounded; headlong she\nFalls to this cistern.  And perchance above\nDoth yet appear the body of a ghost,\nWho here behind me winters.  Him thou know\'st,\nIf thou but newly art arriv\'d below.\nThe years are many that have pass\'d away,\nSince to this fastness Branca Doria ca");
    strcat(expected_filecontent, "me.\"\n     \"Now,\" answer\'d I, \"methinks thou mockest me,\nFor Branca Doria never yet hath died,\nBut doth all natural functions of a man,\nEats, drinks, and sleeps, and putteth raiment on.\"\n     He thus:  \"Not yet unto that upper foss\nBy th\' evil talons guarded, where the pitch\nTenacious boils, had Michael Zanche reach\'d,\nWhen this one left a demon in his stead\nIn his own body, and of one his kin,\nWho with him treachery wrought.  But now put forth\nThy hand, and ope mine eyes.\"  I op\'d them not.\nIll manners were best courtesy to him.\n     Ah Genoese!  men perverse in every way,\nWith every foulness stain\'d, why from the earth\nAre ye not cancel\'d?  Such an one of yours\nI with Romagna\'s darkest spirit found,\nAs for his doings even now in soul\nIs in Cocytus plung\'d, and yet doth seem\nIn body still alive upon the earth.\n\n\n\nCANTO XXXIV\n\n\"THE banners of Hell\'s Monarch do come forth\nTowards us; therefore look,\" so spake my guide,\n\"If thou discern him.\"  As, when");
                
        
                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "PASS");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 13248, file);
                test_error(size == 13248, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 13248 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 13248);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 13248);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 8: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST8(void)
{
    // informacje o teście
    test_start(8, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(12731, 1);
                char expected_filecontent[12732] = "";
        
                strcat(expected_filecontent, "NOW was the day departing, and the air,\nImbrown\'d with shadows, from their toils releas\'d\nAll animals on earth; and I alone\nPrepar\'d myself the conflict to sustain,\nBoth of sad pity, and that perilous road,\nWhich my unerring memory shall retrace.\n     O Muses!  O high genius!  now vouchsafe\nYour aid!  O mind!  that all I saw hast kept\nSafe in a written record, here thy worth\nAnd eminent endowments come to proof.\n     I thus began:  \"Bard!  thou who art my guide,\nConsider well, if virtue be in me\nSufficient, ere to this high enterprise\nThou trust me.  Thou hast told that Silvius\' sire,\nYet cloth\'d in corruptible flesh, among\nTh\' immortal tribes had entrance, and was there\nSensible present.  Yet if heaven\'s great Lord,\nAlmighty foe to ill, such favour shew\'d,\nIn contemplation of the high effect,\nBoth what and who from him should issue forth,\nIt seems in reason\'s judgment well deserv\'d:\nSith he of Rome, and of Rome\'s empire wide,\nIn heaven\'s empyreal height was chosen sire:\nBoth which, if truth be spoken, were ordain\'d\nAnd \'stablish\'d for the holy place, where sits\nWho to great Peter\'s sacred chair succeeds.\nHe from this journey, in thy song renown\'d,\nLearn\'d things, that to his victory gave rise\nAnd to the papal robe.  In after-times\nThe chosen vessel also travel\'d there,\nTo bring us back assurance in that faith,\nWhich is the entrance to salvation\'s way.\nBut I, why should I there presume?  or who\nPermits it?  not, Aeneas I nor Paul.\nMyself I deem not worthy, and none else\nWill deem me.  I, if on this voyage then\nI venture, fear it will in folly end.\nThou, who art wise, better my meaning know\'st,\nThan I can speak.\"  As one, who unresolves\nWhat he hath late resolv\'d, and with new thoughts\nChanges his purpose, from his first intent\nRemov\'d; e\'en such was I on that dun coast,\nWasting in thought my enterprise, at first\nSo eagerly embrac\'d.  \"If right thy words\nI scan,\" replied that shade magnanimous,\n\"Thy soul is by vile fear assail\'d, which oft\nSo overcasts a man, that he recoils\nFrom noblest resolution, like a beast\nAt some false semblance in the twilight gloom.\nThat from this terror thou mayst free thyself,\nI will instruct thee why I came, and what\nI heard in that same instant, when for thee\nGrief touch\'d me first.  I was among the tribe,\nWho rest suspended, when a dame, so blest\nAnd lovely, I besought her to command,\nCall\'d me; her eyes were brighter than the star\nOf day; and she with gentle voice and soft\nAngelically tun\'d her speech address\'d:\n\"O courteous shade of Mantua!  thou whose fame\nYet lives, and shall live long as nature lasts!\nA friend, not of my fortune but myself,\nOn the wide desert in his road has met\nHindrance so great, that he through fear has turn\'d.\nNow much I dread lest he past help have stray\'d,\nAnd I be ris\'n too late for his relief,\nFrom what in heaven of him I heard.  Speed now,\nAnd by thy eloquent persuasive tongue,\nAnd by all means for his deliverance meet,\nAssist him.  So to me will comfort spring.\nI who now bid thee on this errand forth\nAm Beatrice; from a place I come\n\n(Note:  Beatrice.  I use this word, as it is\npronounced in the Italian, as consisting of four\nsyllables, of which the third is a long one.)\n\nRevisited with joy.  Love brought me thence,\nWho prompts my speech.  When in my Master\'s sight\nI stand, thy praise to him I oft will tell.\"\n     She then was silent, and I thus began:\n\"O Lady!  by whose influence alone,\nMankind excels whatever is contain\'d\nWithin that heaven which hath the smallest orb,\nSo thy command delights me, that to obey,\nIf it were done already, would seem late.\nNo need hast thou farther to speak thy will;\nYet tell the reason, why thou art not loth\nTo leave that ample space, where to return\nThou burnest, for this centre here beneath.\"\n     She then:  \"Since thou so deeply wouldst inquire,\nI will instruct thee briefly, why no dread\nHinders my entrance here.  Those things alone\nAre to be fear\'d, whence evil may proceed,\nNone else, for none are terrible beside.\nI am so fram\'d by God, thanks to his grace!\nThat any suff\'rance of your misery\nTouches me not, nor flame of tha");
    strcat(expected_filecontent, "t fierce fire\nAssails me.  In high heaven a blessed dame\nBesides, who mourns with such effectual grief\nThat hindrance, which I send thee to remove,\nThat God\'s stern judgment to her will inclines.\nTo Lucia calling, her she thus bespake:\n\"Now doth thy faithful servant need thy aid\nAnd I commend him to thee.\"  At her word\nSped Lucia, of all cruelty the foe,\nAnd coming to the place, where I abode\nSeated with Rachel, her of ancient days,\nShe thus address\'d me: \"Thou true praise of God!\nBeatrice!  why is not thy succour lent\nTo him, who so much lov\'d thee, as to leave\nFor thy sake all the multitude admires?\nDost thou not hear how pitiful his wail,\nNor mark the death, which in the torrent flood,\nSwoln mightier than a sea, him struggling holds?\"\nNe\'er among men did any with such speed\nHaste to their profit, flee from their annoy,\nAs when these words were spoken, I came here,\nDown from my blessed seat, trusting the force\nOf thy pure eloquence, which thee, and all\nWho well have mark\'d it, into honour brings.\"\n     \"When she had ended, her bright beaming eyes\nTearful she turn\'d aside; whereat I felt\nRedoubled zeal to serve thee.  As she will\'d,\nThus am I come: I sav\'d thee from the beast,\nWho thy near way across the goodly mount\nPrevented.  What is this comes o\'er thee then?\nWhy, why dost thou hang back?  why in thy breast\nHarbour vile fear?  why hast not courage there\nAnd noble daring?  Since three maids so blest\nThy safety plan, e\'en in the court of heaven;\nAnd so much certain good my words forebode.\"\n     As florets, by the frosty air of night\nBent down and clos\'d, when day has blanch\'d their leaves,\nRise all unfolded on their spiry stems;\nSo was my fainting vigour new restor\'d,\nAnd to my heart such kindly courage ran,\nThat I as one undaunted soon replied:\n\"O full of pity she, who undertook\nMy succour!  and thou kind who didst perform\nSo soon her true behest!  With such desire\nThou hast dispos\'d me to renew my voyage,\nThat my first purpose fully is resum\'d.\nLead on: one only will is in us both.\nThou art my guide, my master thou, and lord.\"\n     So spake I; and when he had onward mov\'d,\nI enter\'d on the deep and woody way.\n\n\n\nCANTO III\n\n\"THROUGH me you pass into the city of woe:\nThrough me you pass into eternal pain:\nThrough me among the people lost for aye.\nJustice the founder of my fabric mov\'d:\nTo rear me was the task of power divine,\nSupremest wisdom, and primeval love.\nBefore me things create were none, save things\nEternal, and eternal I endure.\nAll hope abandon ye who enter here.\"\n     Such characters in colour dim I mark\'d\nOver a portal\'s lofty arch inscrib\'d:\nWhereat I thus: \"Master, these words import\nHard meaning.\"  He as one prepar\'d replied:\n\"Here thou must all distrust behind thee leave;\nHere be vile fear extinguish\'d. We are come\nWhere I have told thee we shall see the souls\nTo misery doom\'d, who intellectual good\nHave lost.\"  And when his hand he had stretch\'d forth\nTo mine, with pleasant looks, whence I was cheer\'d,\nInto that secret place he led me on.\n     Here sighs with lamentations and loud moans\nResounded through the air pierc\'d by no star,\nThat e\'en I wept at entering.  Various tongues,\nHorrible languages, outcries of woe,\nAccents of anger, voices deep and hoarse,\nWith hands together smote that swell\'d the sounds,\nMade up a tumult, that for ever whirls\nRound through that air with solid darkness stain\'d,\nLike to the sand that in the whirlwind flies.\n     I then, with error yet encompass\'d, cried:\n\"O master!  What is this I hear?  What race\nAre these, who seem so overcome with woe?\"\n     He thus to me: \"This miserable fate\nSuffer the wretched souls of those, who liv\'d\nWithout or praise or blame, with that ill band\nOf angels mix\'d, who nor rebellious prov\'d\nNor yet were true to God, but for themselves\nWere only.  From his bounds Heaven drove them forth,\nNot to impair his lustre, nor the depth\nOf Hell receives them, lest th\' accursed tribe\nShould glory thence with exultation vain.\"\n     I then: \"Master!  what doth aggrieve them thus,\nThat they lament so loud?\"  He straight replied:\n\"That will I tell thee briefl");
    strcat(expected_filecontent, "y.  These of death\nNo hope may entertain: and their blind life\nSo meanly passes, that all other lots\nThey envy.  Fame of them the world hath none,\nNor suffers; mercy and justice scorn them both.\nSpeak not of them, but look, and pass them by.\"\n     And I, who straightway look\'d, beheld a flag,\nWhich whirling ran around so rapidly,\nThat it no pause obtain\'d: and following came\nSuch a long train of spirits, I should ne\'er\nHave thought, that death so many had despoil\'d.\n     When some of these I recogniz\'d, I saw\nAnd knew the shade of him, who to base fear\nYielding, abjur\'d his high estate.  Forthwith\nI understood for certain this the tribe\nOf those ill spirits both to God displeasing\nAnd to his foes.  These wretches, who ne\'er lived,\nWent on in nakedness, and sorely stung\nBy wasps and hornets, which bedew\'d their cheeks\nWith blood, that mix\'d with tears dropp\'d to their feet,\nAnd by disgustful worms was gather\'d there.\n     Then looking farther onwards I beheld\nA throng upon the shore of a great stream:\nWhereat I thus: \"Sir!  grant me now to know\nWhom here we view, and whence impell\'d they seem\nSo eager to pass o\'er, as I discern\nThrough the blear light?\"  He thus to me in few:\n\"This shalt thou know, soon as our steps arrive\nBeside the woeful tide of Acheron.\"\n     Then with eyes downward cast and fill\'d with shame,\nFearing my words offensive to his ear,\nTill we had reach\'d the river, I from speech\nAbstain\'d.  And lo!  toward us in a bark\nComes on an old man hoary white with eld,\nCrying, \"Woe to you wicked spirits!  hope not\nEver to see the sky again.  I come\nTo take you to the other shore across,\nInto eternal darkness, there to dwell\nIn fierce heat and in ice.  And thou, who there\nStandest, live spirit!  get thee hence, and leave\nThese who are dead.\"  But soon as he beheld\nI left them not, \"By other way,\" said he,\n\"By other haven shalt thou come to shore,\nNot by this passage; thee a nimbler boat\nMust carry.\"  Then to him thus spake my guide:\n\"Charon!  thyself torment not: so \'t is will\'d,\nWhere will and power are one: ask thou no more.\"\n     Straightway in silence fell the shaggy cheeks\nOf him the boatman o\'er the livid lake,\nAround whose eyes glar\'d wheeling flames.  Meanwhile\nThose spirits, faint and naked, color chang\'d,\nAnd gnash\'d their teeth, soon as the cruel words\nThey heard.  God and their parents they blasphem\'d,\nThe human kind, the place, the time, and seed\nThat did engender them and give them birth.\n     Then all together sorely wailing drew\nTo the curs\'d strand, that every man must pass\nWho fears not God.  Charon, demoniac form,\nWith eyes of burning coal, collects them all,\nBeck\'ning, and each, that lingers, with his oar\nStrikes.  As fall off the light autumnal leaves,\nOne still another following, till the bough\nStrews all its honours on the earth beneath;\nE\'en in like manner Adam\'s evil brood\nCast themselves one by one down from the shore,\nEach at a beck, as falcon at his call.\n     Thus go they over through the umber\'d wave,\nAnd ever they on the opposing bank\nBe landed, on this side another throng\nStill gathers.  \"Son,\" thus spake the courteous guide,\n\"Those, who die subject to the wrath of God,\nAll here together come from every clime,\nAnd to o\'erpass the river are not loth:\nFor so heaven\'s justice goads them on, that fear\nIs turn\'d into desire.  Hence ne\'er hath past\nGood spirit.  If of thee Charon complain,\nNow mayst thou know the import of his words.\"\n     This said, the gloomy region trembling shook\nSo terribly, that yet with clammy dews\nFear chills my brow.  The sad earth gave a blast,\nThat, lightening, shot forth a vermilion flame,\nWhich all my senses conquer\'d quite, and I\nDown dropp\'d, as one with sudden slumber seiz\'d.\n\n\n\nCANTO IV\n\nBROKE the deep slumber in my brain a crash\nOf heavy thunder, that I shook myself,\nAs one by main force rous\'d.  Risen upright,\nMy rested eyes I mov\'d around, and search\'d\nWith fixed ken to know what place it was,\nWherein I stood.  For certain on the brink\nI found me of the lamentable vale,\nThe dread abyss, that joins a thund\'rous sound\nOf plaints innumerable.  Dark and d");
    strcat(expected_filecontent, "eep,\nAnd thick with clouds o\'erspread, mine eye in vain\nExplor\'d its bottom, nor could aught discern.\n     \"Now let us to the blind world there beneath\nDescend;\" the bard began all pale of look:\n\"I go the first, and thou shalt follow next.\"\n     Then I his alter\'d hue perceiving, thus:\n\"How may I speed, if thou yieldest to dread,\nWho still art wont to comfort me in doubt?\"\n     He then:  \"The anguish of that race below\nWith pity stains my che");
                
        
                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "WEEK");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 12731, file);
                test_error(size == 12731, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 12731 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 12731);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 12731);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 9: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST9(void)
{
    // informacje o teście
    test_start(9, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(6348, 1);
                char expected_filecontent[6349] = "";
        
                strcat(expected_filecontent, " that gate\nWe enter\'d first, whose threshold is to none\nDenied, nought else so worthy of regard,\nAs is this river, has thine eye discern\'d,\nO\'er which the flaming volley all is quench\'d.\"\n     So spake my guide; and I him thence besought,\nThat having giv\'n me appetite to know,\nThe food he too would give, that hunger crav\'d.\n     \"In midst of ocean,\" forthwith he began,\n\"A desolate country lies, which Crete is nam\'d,\nUnder whose monarch in old times the world\nLiv\'d pure and chaste.  A mountain rises there,\nCall\'d Ida, joyous once with leaves and streams,\nDeserted now like a forbidden thing.\nIt was the spot which Rhea, Saturn\'s spouse,\nChose for the secret cradle of her son;\nAnd better to conceal him, drown\'d in shouts\nHis infant cries.  Within the mount, upright\nAn ancient form there stands and huge, that turns\nHis shoulders towards Damiata, and at Rome\nAs in his mirror looks.  Of finest gold\nHis head is shap\'d, pure silver are the breast\nAnd arms; thence to the middle is of brass.\nAnd downward all beneath well-temper\'d steel,\nSave the right foot of potter\'s clay, on which\nThan on the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to the lowest depth of all,\nForm there Cocytus, of whose lake (thyself\nShall see it) I here give thee no account.\"\n     Then I to him:  \"If from our world this sluice\nBe thus deriv\'d; wherefore to us but now\nAppears it at this edge?\"  He straight replied:\n\"The place, thou know\'st, is round; and though great part\nThou have already pass\'d, still to the left\nDescending to the nethermost, not yet\nHast thou the circuit made of the whole orb.\nWherefore if aught of new to us appear,\nIt needs not bring up wonder in thy looks.\"\n     Then I again inquir\'d:  \"Where flow the streams\nOf Phlegethon and Lethe? for of one\nThou tell\'st not, and the other of that shower,\nThou say\'st, is form\'d.\"  He answer thus return\'d:\n\"Doubtless thy questions all well pleas\'d I hear.\nYet the red seething wave might have resolv\'d\nOne thou proposest.  Lethe thou shalt see,\nBut not within this hollow, in the place,\nWhither to lave themselves the spirits go,\nWhose blame hath been by penitence remov\'d.\"\nHe added:  \"Time is now we quit the wood.\nLook thou my steps pursue:  the margins give\nSafe passage, unimpeded by the flames;\nFor over them all vapour is extinct.\"\n\n\n\nCANTO XV\n\nOne of the solid margins bears us now\nEnvelop\'d in the mist, that from the stream\nArising, hovers o\'er, and saves from fire\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the mounds,\nSo fram\'d, though not in height or bulk to these\nMade equal, by the master, whosoe\'er\nHe was, that rais\'d them here.  We from the wood\nWere not so far remov\'d, that turning round\nI might not have discern\'d it, when we met\nA troop of spirits, who came beside the pier.\n     They each one ey\'d us, as at eventide\nOne eyes another under a new moon,\nAnd toward us sharpen\'d their sight as keen,\nAs an old tailor at his needle\'s eye.\n     Thus narrowly explor\'d by all the tribe,\nI was agniz\'d of one, who by the skirt\nCaught me, and cried, \"What wonder have we here!\"\n     And I, when he to me outstretch\'d his arm,\nIntently fix\'d my ken on his parch\'d looks,\nThat although smirch\'d with fire, they hinder\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent");
    strcat(expected_filecontent, ";\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefore on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path descend to tread\nOn equal ground with him, but held my head\nBent down, as one who walks in reverent guise.\n     \"What chance or destiny,\" thus be began,\n\"Ere the last day conducts thee here below?\nAnd who is this, that shows to thee the way?\"\n     \"There up aloft,\" I answer\'d, \"in the life\nSerene, I wander\'d in a valley lost,\nBefore mine age had to its fullness reach\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d, and now strikes full upon my heart\nThe dear, benign, paternal image, such\nAs thine was, when so lately thou didst teach me\nThe way for man to win eternity;\nAnd how I priz\'d t");
                
        
                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "FIT.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 6348, file);
                test_error(size == 6348, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6348 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6348);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 6348);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 10: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST10(void)
{
    // informacje o teście
    test_start(10, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(6363, 1);
                char expected_filecontent[6364] = "";
        
                strcat(expected_filecontent, "emons on our way we went;\nAh fearful company!  but in the church\nWith saints, with gluttons at the tavern\'s mess.\n     Still earnest on the pitch I gaz\'d, to mark\nAll things whate\'er the chasm contain\'d, and those\nWho burn\'d within.  As dolphins, that, in sign\nTo mariners, heave high their arched backs,\nThat thence forewarn\'d they may advise to save\nTheir threaten\'d vessels; so, at intervals,\nTo ease the pain his back some sinner show\'d,\nThen hid more nimbly than the lightning glance.\n     E\'en as the frogs, that of a wat\'ry moat\nStand at the brink, with the jaws only out,\nTheir feet and of the trunk all else concealed,\nThus on each part the sinners stood, but soon\nAs Barbariccia was at hand, so they\nDrew back under the wave.  I saw, and yet\nMy heart doth stagger, one, that waited thus,\nAs it befalls that oft one frog remains,\nWhile the next springs away:  and Graffiacan,\nWho of the fiends was nearest, grappling seiz\'d\nHis clotted locks, and dragg\'d him sprawling up,\nThat he appear\'d to me an otter.  Each\nAlready by their names I knew, so well\nWhen they were chosen, I observ\'d, and mark\'d\nHow one the other call\'d. \"O Rubicant!\nSee that his hide thou with thy talons flay,\"\nShouted together all the cursed crew.\n     Then I:  \"Inform thee, master!  if thou may,\nWhat wretched soul is this, on whom their hand\nHis foes have laid.\"  My leader to his side\nApproach\'d, and whence he came inquir\'d, to whom\nWas answer\'d thus:  \"Born in Navarre\'s domain\nMy mother plac\'d me in a lord\'s retinue,\nFor she had borne me to a losel vile,\nA spendthrift of his substance and himself.\nThe good king Thibault after that I serv\'d,\nTo peculating here my thoughts were turn\'d,\nWhereof I give account in this dire heat.\"\n     Straight Ciriatto, from whose mouth a tusk\nIssued on either side, as from a boar,\nRipt him with one of these.  \'Twixt evil claws\nThe mouse had fall\'n:  but Barbariccia cried,\nSeizing him with both arms:  \"Stand thou apart,\nWhile I do fix him on my prong transpierc\'d.\"\nThen added, turning to my guide his face,\n\"Inquire of him, if more thou wish to learn,\nEre he again be rent.\"  My leader thus:\n\"Then tell us of the partners in thy guilt;\nKnowest thou any sprung of Latian land\nUnder the tar?\"--\"I parted,\" he replied,\n\"But now from one, who sojourn\'d not far thence;\nSo were I under shelter now with him!\nNor hook nor talon then should scare me more.\"--.\n     \"Too long we suffer,\" Libicocco cried,\nThen, darting forth a prong, seiz\'d on his arm,\nAnd mangled bore away the sinewy part.\nHim Draghinazzo by his thighs beneath\nWould next have caught, whence angrily their chief,\nTurning on all sides round, with threat\'ning brow\nRestrain\'d them.  When their strife a little ceas\'d,\nOf him, who yet was gazing on his wound,\nMy teacher thus without delay inquir\'d:\n\"Who was the spirit, from whom by evil hap\nParting, as thou has told, thou cam\'st to shore?\"--\n     \"It was the friar Gomita,\" he rejoin\'d,\n\"He of Gallura, vessel of all guile,\nWho had his master\'s enemies in hand,\nAnd us\'d them so that they commend him well.\nMoney he took, and them at large dismiss\'d.\nSo he reports:  and in each other charge\nCommitted to his keeping, play\'d the part\nOf barterer to the height:   with him doth herd\nThe chief of Logodoro, Michel Zanche.\nSardinia is a theme, whereof their tongue\nIs never weary.  Out! alas! behold\nThat other, how he grins!  More would I say,\nBut tremble lest he mean to maul me sore.\"\n     Their captain then to Farfarello turning,\nWho roll\'d his moony eyes in act to strike,\nRebuk\'d him thus:  \"Off! cursed bird! Avaunt!\"--\n     \"If ye desire to see or hear,\" he thus\nQuaking with dread resum\'d, \"or Tuscan spirits\nOr Lombard, I will cause them to appear.\nMeantime let these ill talons bate their fury,\nSo that no vengeance they may fear from them,\nAnd I, remaining in this self-same place,\nWill for myself but one, make sev\'n appear,\nWhen my shrill whistle shall be heard; for so\nOur custom is to call each other up.\"\n     Cagnazzo at that word deriding grinn\'d,\nThen wagg\'d the head and spake:  \"Hear his device,\nMischievous as he is, to plunge him down");
    strcat(expected_filecontent, ".\"\n     Whereto he thus, who fail\'d not in rich store\nOf nice-wove toils; \" Mischief forsooth extreme,\nMeant only to procure myself more woe!\"\n     No longer Alichino then refrain\'d,\nBut thus, the rest gainsaying, him bespake:\n\"If thou do cast thee down, I not on foot\nWill chase thee, but above the pitch will beat\nMy plumes.  Quit we the vantage ground, and let\nThe bank be as a shield, that we may see\nIf singly thou prevail against us all.\"\n     Now, reader, of new sport expect to hear!\n     They each one turn\'d his eyes to the\' other shore,\nHe first, who was the hardest to persuade.\nThe spirit of Navarre chose well his time,\nPlanted his feet on land, and at one leap\nEscaping disappointed their resolve.\n     Them quick resentment stung, but him the most,\nWho was the cause of failure; in pursuit\nHe therefore sped, exclaiming;  \"Thou art caught.\"\n     But little it avail\'d:  terror outstripp\'d\nHis following flight:  the other plung\'d beneath,\nAnd he with upward pinion rais\'d his breast:\nE\'en thus the water-fowl, when she perceives\nThe falcon near, dives instant down, while he\nEnrag\'d and spent retires.  That mockery\nIn Calcabrina fury stirr\'d, who flew\nAfter him, with desire of strife inflam\'d;\nAnd, for the barterer had \'scap\'d, so turn\'d\nHis talons on his comrade. O\'er the dyke\nIn grapple close they join\'d; but the\' other prov\'d\nA goshawk able to rend well his foe;\nAnd in the boiling lake both fell.  The heat\nWas umpire soon between them, but in vain\nTo lift themselves they strove, so fast were glued\nTheir pennons.  Barbariccia, as the rest,\nThat chance lamenting, four in flight dispatch\'d\nFrom the\' other coast, with all their weapons arm\'d.\nThey, to their post on each side speedily\nDescending, stretch\'d their hooks toward the fiends,\nWho flounder\'d, inly burning from their scars:\nAnd we departing left them to that broil.\n\n\n\nCANTO XXIII\n\nIN silence and in solitude we went,\nOne first, the other following his steps,\nAs minor friars journeying on their road.\n     The present fray had turn\'d my thoughts to muse\nUpon old Aesop\'s fable, where he told\nWhat fate unto the mouse and frog befell.\nFor language hath not sounds more like in sense,\nThan are these chances, if the origin\nAnd end of each be heedfully compar\'d.\nAnd as one thought b");
                
        
                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "ORDER.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 6363, file);
                test_error(size == 6363, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6363 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6363);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 6363);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 11: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST11(void)
{
    // informacje o teście
    test_start(11, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(1461, 1);
                char expected_filecontent[1462] = "";
        
                strcat(expected_filecontent, "mpts them,\nThey wait not for the motions of the will\nIn natures most sincere.  I did but smile,\nAs one who winks; and thereupon the shade\nBroke off, and peer\'d into mine eyes, where best\nOur looks interpret. \"So to good event\nMayst thou conduct such great emprize,\" he cried,\n\"Say, why across thy visage beam\'d, but now,\nThe lightning of a smile!\"  On either part\nNow am I straiten\'d; one conjures me speak,\nTh\' other to silence binds me: whence a sigh\nI utter, and the sigh is heard.  \"Speak on; \"\nThe teacher cried;  \"and do not fear to speak,\nBut tell him what so earnestly he asks.\"\nWhereon I thus:  \"Perchance, O ancient spirit!\nThou marvel\'st at my smiling. There is room\nFor yet more wonder.  He who guides my ken\nOn high, he is that Mantuan, led by whom\nThou didst presume of men arid gods to sing.\nIf other cause thou deem\'dst for which I smil\'d,\nLeave it as not the true one; and believe\nThose words, thou spak\'st of him, indeed the cause.\"\n     Now down he bent t\' embrace my teacher\'s feet;\nBut he forbade him:  \"Brother!  do it not:\nThou art a shadow, and behold\'st a shade.\"\nHe rising answer\'d thus:  \"Now hast thou prov\'d\nThe force and ardour of the love I bear thee,\nWhen I forget we are but things of air,\nAnd as a substance treat an empty shade.\"\n\n\n\nCANTO XXII\n\nNow we had left the angel, who had turn\'d\nTo the sixth circle our ascending step,\nOne gash from off my forehead raz\'d: while they,\nWhose wishes tend to justice, shouted forth:\n\"Bles");
                
        
                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "CASE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 1461, file);
                test_error(size == 1461, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1461 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1461);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 1461);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 12: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST12(void)
{
    // informacje o teście
    test_start(12, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(914, 1);
                char expected_filecontent[915] = "";
        
                strcat(expected_filecontent, "e had tended still\nThe thread and cordwain; and too late repents.\n     \"See next the wretches, who the needle left,\nThe shuttle and the spindle, and became\nDiviners:  baneful witcheries they wrought\nWith images and herbs.  But onward now:\nFor now doth Cain with fork of thorns confine\nOn either hemisphere, touching the wave\nBeneath the towers of Seville.  Yesternight\nThe moon was round.  Thou mayst remember well:\nFor she good service did thee in the gloom\nOf the deep wood.\"  This said, both onward mov\'d.\n\n\n\nCANTO XXI\n\nTHUS we from bridge to bridge, with other talk,\nThe which my drama cares not to rehearse,\nPass\'d on; and to the summit reaching, stood\nTo view another gap, within the round\nOf Malebolge, other bootless pangs.\n     Marvelous darkness shadow\'d o\'er the place.\n     In the Venetians\' arsenal as boils\nThrough wintry months tenacious pitch, to smear\nTheir unsound vessels; for th\' inclement time");
                
        
                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "FINALFIG.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 914, file);
                test_error(size == 914, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 914 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 914);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 914);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 13: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST13(void)
{
    // informacje o teście
    test_start(13, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(10240, 1);
                char expected_filecontent[10241] = "";

                strcat(expected_filecontent, "s Beatrice?\"--\"See her,\" she replied,\n\"Beneath the fresh leaf seated on its root.\nBehold th\' associate choir that circles her.\nThe others, with a melody more sweet\nAnd more profound, journeying to higher realms,\nUpon the Gryphon tend.\"  If there her words\nWere clos\'d, I know not; but mine eyes had now\nTa\'en view of her, by whom all other thoughts\nWere barr\'d admittance.  On the very ground\nAlone she sat, as she had there been left\nA guard upon the wain, which I beheld\nBound to the twyform beast.  The seven nymphs\nDid make themselves a cloister round about her,\nAnd in their hands upheld those lights secure\nFrom blast septentrion and the gusty south.\n     \"A little while thou shalt be forester here:\nAnd citizen shalt be forever with me,\nOf that true Rome, wherein Christ dwells a Roman\nTo profit the misguided world, keep now\nThine eyes upon the car; and what thou seest,\nTake heed thou write, returning to that place.\"\n     Thus Beatrice: at whose feet inclin\'d\nDevout, at her behest, my thought and eyes,\nI, as she bade, directed.  Never fire,\nWith so swift motion, forth a stormy cloud\nLeap\'d downward from the welkin\'s farthest bound,\nAs I beheld the bird of Jove descending\nPounce on the tree, and, as he rush\'d, the rind,\nDisparting crush beneath him, buds much more\nAnd leaflets.  On the car with all his might\nHe struck, whence, staggering like a ship, it reel\'d,\nAt random driv\'n, to starboard now, o\'ercome,\nAnd now to larboard, by the vaulting waves.\n     Next springing up into the chariot\'s womb\nA fox I saw, with hunger seeming pin\'d\nOf all good food.  But, for his ugly sins\nThe saintly maid rebuking him, away\nScamp\'ring he turn\'d, fast as his hide-bound corpse\nWould bear him.  Next, from whence before he came,\nI saw the eagle dart into the hull\nO\' th\' car, and leave it with his feathers lin\'d;\nAnd then a voice, like that which issues forth\nFrom heart with sorrow riv\'d, did issue forth\nFrom heav\'n, and, \"O poor bark of mine!\" it cried,\n\"How badly art thou freighted!\"  Then, it seem\'d,\nThat the earth open\'d between either wheel,\nAnd I beheld a dragon issue thence,\nThat through the chariot fix\'d his forked train;\nAnd like a wasp that draggeth back the sting,\nSo drawing forth his baleful train, he dragg\'d\nPart of the bottom forth, and went his way\nExulting.  What remain\'d, as lively turf\nWith green herb, so did clothe itself with plumes,\nWhich haply had with purpose chaste and kind\nBeen offer\'d; and therewith were cloth\'d the wheels,\nBoth one and other, and the beam, so quickly\nA sigh were not breath\'d sooner.  Thus transform\'d,\nThe holy structure, through its several parts,\nDid put forth heads, three on the beam, and one\nOn every side; the first like oxen horn\'d,\nBut with a single horn upon their front\nThe four.  Like monster sight hath never seen.\nO\'er it methought there sat, secure as rock\nOn mountain\'s lofty top, a shameless whore,\nWhose ken rov\'d loosely round her.  At her side,\nAs \'t were that none might bear her off, I saw\nA giant stand; and ever, and anon\nThey mingled kisses.  But, her lustful eyes\nChancing on me to wander, that fell minion\nScourg\'d her from head to foot all o\'er; then full\nOf jealousy, and fierce with rage, unloos\'d\nThe monster, and dragg\'d on, so far across\nThe forest, that from me its shades alone\nShielded the harlot and the new-form\'d brute.\n\n\n\nCANTO XXXIII\n\n\"The heathen, Lord!  are come!\" responsive thus,\nThe trinal now, and now the virgin band\nQuaternion, their sweet psalmody began,\nWeeping; and Beatrice listen\'d, sad\nAnd sighing, to the song\', in such a mood,\nThat Mary, as she stood beside the cross,\nWas scarce more chang\'d.  But when they gave her place\nTo speak, then, risen upright on her feet,\nShe, with a colour glowing bright as fire,\nDid answer: \"Yet a little while, and ye\nShall see me not; and, my beloved sisters,\nAgain a little while, and ye shall see me.\"\n     Before her then she marshall\'d all the seven,\nAnd, beck\'ning only motion\'d me, the dame,\nAnd that remaining sage, to follow her.\n     So on she pass\'d; and had not set, I ween,\nHer tenth step to the ground, when with mine eyes\nHer ");
    strcat(expected_filecontent, "eyes encounter\'d; and, with visage mild,\n\"So mend thy pace,\" she cried, \"that if my words\nAddress thee, thou mayst still be aptly plac\'d\nTo hear them.\"  Soon as duly to her side\nI now had hasten\'d:  \"Brother!\" she began,\n\"Why mak\'st thou no attempt at questioning,\nAs thus we walk together?\"  Like to those\nWho, speaking with too reverent an awe\nBefore their betters, draw not forth the voice\nAlive unto their lips, befell me shell\nThat I in sounds imperfect thus began:\n\"Lady!  what I have need of, that thou know\'st,\nAnd what will suit my need.\"  She answering thus:\n\"Of fearfulness and shame, I will, that thou\nHenceforth do rid thee: that thou speak no more,\nAs one who dreams.  Thus far be taught of me:\nThe vessel, which thou saw\'st the serpent break,\nWas and is not: let him, who hath the blame,\nHope not to scare God\'s vengeance with a sop.\nWithout an heir for ever shall not be\nThat eagle, he, who left the chariot plum\'d,\nWhich monster made it first and next a prey.\nPlainly I view, and therefore speak, the stars\nE\'en now approaching, whose conjunction, free\nFrom all impediment and bar, brings on\nA season, in the which, one sent from God,\n(Five hundred, five, and ten, do mark him out)\nThat foul one, and th\' accomplice of her guilt,\nThe giant, both shall slay.  And if perchance\nMy saying, dark as Themis or as Sphinx,\nFail to persuade thee, (since like them it foils\nThe intellect with blindness) yet ere long\nEvents shall be the Naiads, that will solve\nThis knotty riddle, and no damage light\nOn flock or field.  Take heed; and as these words\nBy me are utter\'d, teach them even so\nTo those who live that life, which is a race\nTo death: and when thou writ\'st them, keep in mind\nNot to conceal how thou hast seen the plant,\nThat twice hath now been spoil\'d.  This whoso robs,\nThis whoso plucks, with blasphemy of deed\nSins against God, who for his use alone\nCreating hallow\'d it.  For taste of this,\nIn pain and in desire, five thousand years\nAnd upward, the first soul did yearn for him,\nWho punish\'d in himself the fatal gust.\n     \"Thy reason slumbers, if it deem this height\nAnd summit thus inverted of the plant,\nWithout due cause: and were not vainer thoughts,\nAs Elsa\'s numbing waters, to thy soul,\nAnd their fond pleasures had not dyed it dark\nAs Pyramus the mulberry, thou hadst seen,\nIn such momentous circumstance alone,\nGod\'s equal justice morally implied\nIn the forbidden tree.  But since I mark thee\nIn understanding harden\'d into stone,\nAnd, to that hardness, spotted too and stain\'d,\nSo that thine eye is dazzled at my word,\nI will, that, if not written, yet at least\nPainted thou take it in thee, for the cause,\nThat one brings home his staff inwreath\'d with palm.\n     \"I thus:  \"As wax by seal, that changeth not\nIts impress, now is stamp\'d my brain by thee.\nBut wherefore soars thy wish\'d-for speech so high\nBeyond my sight, that loses it the more,\nThe more it strains to reach it?\" --\"To the end\nThat thou mayst know,\" she answer\'d straight, \"the school,\nThat thou hast follow\'d; and how far behind,\nWhen following my discourse, its learning halts:\nAnd mayst behold your art, from the divine\nAs distant, as the disagreement is\n\'Twixt earth and heaven\'s most high and rapturous orb.\"\n     \"I not remember,\" I replied, \"that e\'er\nI was estrang\'d from thee, nor for such fault\nDoth conscience chide me.\"  Smiling she return\'d:\n\"If thou canst, not remember, call to mind\nHow lately thou hast drunk of Lethe\'s wave;\nAnd, sure as smoke doth indicate a flame,\nIn that forgetfulness itself conclude\nBlame from thy alienated will incurr\'d.\nFrom henceforth verily my words shall be\nAs naked as will suit them to appear\nIn thy unpractis\'d view.\"  More sparkling now,\nAnd with retarded course the sun possess\'d\nThe circle of mid-day, that varies still\nAs th\' aspect varies of each several clime,\nWhen, as one, sent in vaward of a troop\nFor escort, pauses, if perchance he spy\nVestige of somewhat strange and rare: so paus\'d\nThe sev\'nfold band, arriving at the verge\nOf a dun umbrage hoar, such as is seen,\nBeneath green leaves and gloomy branches, oft\nTo overbrow a bleak ");
    strcat(expected_filecontent, "and alpine cliff.\nAnd, where they stood, before them, as it seem\'d,\nTigris and Euphrates both beheld,\nForth from one fountain issue; and, like friends,\nLinger at parting. \"O enlight\'ning beam!\nO glory of our kind!  beseech thee say\nWhat water this, which from one source deriv\'d\nItself removes to distance from itself?\"\n     To such entreaty answer thus was made:\n\"Entreat Matilda, that she teach thee this.\"\n     And here, as one, who clears himself of blame\nImputed, the fair dame return\'d:  \"Of me\nHe this and more hath learnt; and I am safe\nThat Lethe\'s water hath not hid it from him.\"\n     And Beatrice:  \"Some more pressing care\nThat oft the memory \'reeves, perchance hath made\nHis mind\'s eye dark.  But lo!  where Eunoe cows!\nLead thither; and, as thou art wont, revive\nHis fainting virtue.\"  As a courteous spirit,\nThat proffers no excuses, but as soon\nAs he hath token of another\'s will,\nMakes it his own; when she had ta\'en me, thus\nThe lovely maiden mov\'d her on, and call\'d\nTo Statius with an air most lady-like:\n\"Come thou with him.\"  Were further space allow\'d,\nThen, Reader, might I sing, though but in part,\nThat beverage, with whose sweetness I had ne\'er\nBeen sated.  But, since all the leaves are full,\nAppointed for this second strain, mine art\nWith warning bridle checks me.  I return\'d\nFrom the most holy wave, regenerate,\nIf \'en as new plants renew\'d with foliage new,\nPure and made apt for mounting to the stars.\n\n\n\nNOTES TO PURGATORY\n\nCANTO I\n\nVerse 1.  O\'er better waves.]  Berni, Orl. Inn. L 2. c. i.\nPer correr maggior acqua alza le vele,\nO debil navicella del mio ingegno.\n\nv. 11.  Birds of chattering note.]  For the fable of the\ndaughters of Pierus, who challenged the muses to sing, and were\nby them\nchanged into magpies, see Ovid, Met. 1. v. fab. 5.\n\nv. 19.  Planet.]  Venus.\n\nv. 20.  Made all the orient laugh.]  Hence Chaucer, Knight\'s\nTale: And all the orisont laugheth of the sight.\n\nIt is sometimes read \"orient.\"\n\nv. 24.  Four stars.]  Symbolical of the four cardinal virtues,\nPrudence Justice, Fortitude, and T");

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "LIKE.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 10702, file);
                test_error(size == 10240, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 10240 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 10240);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 10240);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 14: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST14(void)
{
    // informacje o teście
    test_start(14, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(13248, 1);
                char expected_filecontent[13249] = "";

                strcat(expected_filecontent, ", if chance a passing cloud\nSo sail across, that opposite it hangs,\nSuch then Antaeus seem\'d, as at mine ease\nI mark\'d him stooping.  I were fain at times\nT\' have pass\'d another way.  Yet in th\' abyss,\nThat Lucifer with Judas low ingulfs,\nI,ightly he plac\'d us; nor there leaning stay\'d,\nBut rose as in a bark the stately mast.\n\n\n\nCANTO XXXII\n\nCOULD I command rough rhimes and hoarse, to suit\nThat hole of sorrow, o\'er which ev\'ry rock\nHis firm abutment rears, then might the vein\nOf fancy rise full springing:  but not mine\nSuch measures, and with falt\'ring awe I touch\nThe mighty theme; for to describe the depth\nOf all the universe, is no emprize\nTo jest with, and demands a tongue not us\'d\nTo infant babbling.  But let them assist\nMy song, the tuneful maidens, by whose aid\nAmphion wall\'d in Thebes, so with the truth\nMy speech shall best accord.  Oh ill-starr\'d folk,\nBeyond all others wretched!  who abide\nIn such a mansion, as scarce thought finds words\nTo speak of, better had ye here on earth\nBeen flocks or mountain goats.  As down we stood\nIn the dark pit beneath the giants\' feet,\nBut lower far than they, and I did gaze\nStill on the lofty battlement, a voice\nBespoke me thus:  \"Look how thou walkest.  Take\nGood heed, thy soles do tread not on the heads\nOf thy poor brethren.\"  Thereupon I turn\'d,\nAnd saw before and underneath my feet\nA lake, whose frozen surface liker seem\'d\nTo glass than water.  Not so thick a veil\nIn winter e\'er hath Austrian Danube spread\nO\'er his still course, nor Tanais far remote\nUnder the chilling sky.  Roll\'d o\'er that mass\nHad Tabernich or Pietrapana fall\'n,\nNot e\'en its rim had creak\'d. As peeps the frog\nCroaking above the wave, what time in dreams\nThe village gleaner oft pursues her toil,\nSo, to where modest shame appears, thus low\nBlue pinch\'d and shrin\'d in ice the spirits stood,\nMoving their teeth in shrill note like the stork.\nHis face each downward held; their mouth the cold,\nTheir eyes express\'d the dolour of their heart.\n     A space I look\'d around, then at my feet\nSaw two so strictly join\'d, that of their head\nThe very hairs were mingled.  \"Tell me ye,\nWhose bosoms thus together press,\" said I,\n\"Who are ye?\"  At that sound their necks they bent,\nAnd when their looks were lifted up to me,\nStraightway their eyes, before all moist within,\nDistill\'d upon their lips, and the frost bound\nThe tears betwixt those orbs and held them there.\nPlank unto plank hath never cramp clos\'d up\nSo stoutly.  Whence like two enraged goats\nThey clash\'d together; them such fury seiz\'d.\n     And one, from whom the cold both ears had reft,\nExclaim\'d, still looking downward: \"Why on us\nDost speculate so long?  If thou wouldst know\nWho are these two, the valley, whence his wave\nBisenzio slopes, did for its master own\nTheir sire Alberto, and next him themselves.\nThey from one body issued; and throughout\nCaina thou mayst search, nor find a shade\nMore worthy in congealment to be fix\'d,\nNot him, whose breast and shadow Arthur\'s land\nAt that one blow dissever\'d, not Focaccia,\nNo not this spirit, whose o\'erjutting head\nObstructs my onward view:  he bore the name\nOf Mascheroni:  Tuscan if thou be,\nWell knowest who he was:  and to cut short\nAll further question, in my form behold\nWhat once was Camiccione.  I await\nCarlino here my kinsman, whose deep guilt\nShall wash out mine.\"  A thousand visages\nThen mark\'d I, which the keen and eager cold\nHad shap\'d into a doggish grin; whence creeps\nA shiv\'ring horror o\'er me, at the thought\nOf those frore shallows.  While we journey\'d on\nToward the middle, at whose point unites\nAll heavy substance, and I trembling went\nThrough that eternal chillness, I know not\nIf will it were or destiny, or chance,\nBut, passing \'midst the heads, my foot did strike\nWith violent blow against the face of one.\n     \"Wherefore dost bruise me?\" weeping, he exclaim\'d,\n\"Unless thy errand be some fresh revenge\nFor Montaperto, wherefore troublest me?\"\n     I thus:  \"Instructor, now await me here,\nThat I through him may rid me of my doubt.\nThenceforth what haste thou wilt.\"  The teacher paus\'d,\nAnd to that shade I s");
    strcat(expected_filecontent, "pake, who bitterly\nStill curs\'d me in his wrath.  \"What art thou, speak,\nThat railest thus on others?\"  He replied:\n\"Now who art thou, that smiting others\' cheeks\nThrough Antenora roamest, with such force\nAs were past suff\'rance, wert thou living still?\"\n     \"And I am living, to thy joy perchance,\"\nWas my reply, \"if fame be dear to thee,\nThat with the rest I may thy name enrol.\"\n     \"The contrary of what I covet most,\"\nSaid he, \"thou tender\'st:  hence; nor vex me more.\nIll knowest thou to flatter in this vale.\"\n     Then seizing on his hinder scalp, I cried:\n\"Name thee, or not a hair shall tarry here.\"\n     \"Rend all away,\" he answer\'d, \"yet for that\nI will not tell nor show thee who I am,\nThough at my head thou pluck a thousand times.\"\n     Now I had grasp\'d his tresses, and stript off\nMore than one tuft, he barking, with his eyes\nDrawn in and downward, when another cried,\n\"What ails thee, Bocca?  Sound not loud enough\nThy chatt\'ring teeth, but thou must bark outright?\nWhat devil wrings thee?\"--\" Now,\" said I, \"be dumb,\nAccursed traitor!  to thy shame of thee\nTrue tidings will I bear.\"--\" Off,\" he replied,\n\"Tell what thou list; but as thou escape from hence\nTo speak of him whose tongue hath been so glib,\nForget not:  here he wails the Frenchman\'s gold.\n\'Him of Duera,\' thou canst say, \'I mark\'d,\nWhere the starv\'d sinners pine.\'  If thou be ask\'d\nWhat other shade was with them, at thy side\nIs Beccaria, whose red gorge distain\'d\nThe biting axe of Florence.  Farther on,\nIf I misdeem not, Soldanieri bides,\nWith Ganellon, and Tribaldello, him\nWho op\'d Faenza when the people slept.\"\n     We now had left him, passing on our way,\nWhen I beheld two spirits by the ice\nPent in one hollow, that the head of one\nWas cowl unto the other; and as bread\nIs raven\'d up through hunger, th\' uppermost\nDid so apply his fangs to th\' other\'s brain,\nWhere the spine joins it.  Not more furiously\nOn Menalippus\' temples Tydeus gnaw\'d,\nThan on that skull and on its garbage he.\n     \"O thou who show\'st so beastly sign of hate\n\'Gainst him thou prey\'st on, let me hear,\" said I\n\"The cause, on such condition, that if right\nWarrant thy grievance, knowing who ye are,\nAnd what the colour of his sinning was,\nI may repay thee in the world above,\nIf that, wherewith I speak be moist so long.\"\n\n\n\nCANTO XXXIII\n\nHIS jaws uplifting from their fell repast,\nThat sinner wip\'d them on the hairs o\' th\' head,\nWhich he behind had mangled, then began:\n\"Thy will obeying, I call up afresh\nSorrow past cure, which but to think of wrings\nMy heart, or ere I tell on\'t. But if words,\nThat I may utter, shall prove seed to bear\nFruit of eternal infamy to him,\nThe traitor whom I gnaw at, thou at once\nShalt see me speak and weep.  Who thou mayst be\nI know not, nor how here below art come:\nBut Florentine thou seemest of a truth,\nWhen I do hear thee.  Know I was on earth\nCount Ugolino, and th\' Archbishop he\nRuggieri.  Why I neighbour him so close,\nNow list.  That through effect of his ill thoughts\nIn him my trust reposing, I was ta\'en\nAnd after murder\'d, need is not I tell.\nWhat therefore thou canst not have heard, that is,\nHow cruel was the murder, shalt thou hear,\nAnd know if he have wrong\'d me.  A small grate\nWithin that mew, which for my sake the name\nOf famine bears, where others yet must pine,\nAlready through its opening sev\'ral moons\nHad shown me, when I slept the evil sleep,\nThat from the future tore the curtain off.\nThis one, methought, as master of the sport,\nRode forth to chase the gaunt wolf and his whelps\nUnto the mountain, which forbids the sight\nOf Lucca to the Pisan.  With lean brachs\nInquisitive and keen, before him rang\'d\nLanfranchi with Sismondi and Gualandi.\nAfter short course the father and the sons\nSeem\'d tir\'d and lagging, and methought I saw\nThe sharp tusks gore their sides.  When I awoke\nBefore the dawn, amid their sleep I heard\nMy sons (for they were with me) weep and ask\nFor bread.  Right cruel art thou, if no pang\nThou feel at thinking what my heart foretold;\nAnd if not now, why use thy tears to flow?\nNow had they waken\'d; and the hour drew near\nWhen they we");
    strcat(expected_filecontent, "re wont to bring us food; the mind\nOf each misgave him through his dream, and I\nHeard, at its outlet underneath lock\'d up\nThe\' horrible tower:  whence uttering not a word\nI look\'d upon the visage of my sons.\nI wept not:  so all stone I felt within.\nThey wept:  and one, my little Anslem, cried:\n\"Thou lookest so!  Father what ails thee?\"  Yet\nI shed no tear, nor answer\'d all that day\nNor the next night, until another sun\nCame out upon the world.  When a faint beam\nHad to our doleful prison made its way,\nAnd in four countenances I descry\'d\nThe image of my own, on either hand\nThrough agony I bit, and they who thought\nI did it through desire of feeding, rose\nO\' th\' sudden, and cried, \'Father, we should grieve\nFar less, if thou wouldst eat of us: thou gav\'st\nThese weeds of miserable flesh we wear,\nAnd do thou strip them off from us again.\'\nThen, not to make them sadder, I kept down\nMy spirit in stillness.  That day and the next\nWe all were silent.  Ah, obdurate earth!\nWhy open\'dst not upon us?  When we came\nTo the fourth day, then Geddo at my feet\nOutstretch\'d did fling him, crying, \'Hast no help\nFor me, my father!\'  \"There he died, and e\'en\nPlainly as thou seest me, saw I the three\nFall one by one \'twixt the fifth day and sixth:\nWhence I betook me now grown blind to grope\nOver them all, and for three days aloud\nCall\'d on them who were dead.  Then fasting got\nThe mastery of grief.\"  Thus having spoke,\nOnce more upon the wretched skull his teeth\nHe fasten\'d, like a mastiff\'s \'gainst the bone\nFirm and unyielding.  Oh thou Pisa!  shame\nOf all the people, who their dwelling make\nIn that fair region, where th\' Italian voice\nIs heard, since that thy neighbours are so slack\nTo punish, from their deep foundations rise\nCapraia and Gorgona, and dam up\nThe mouth of Arno, that each soul in thee\nMay perish in the waters!  What if fame\nReported that thy castles were betray\'d\nBy Ugolino, yet no right hadst thou\nTo stretch his children on the rack.  For them,\nBrigata, Ugaccione, and the pair\nOf gentle ones, of whom my song hath told,\nTheir tender years, thou modern Thebes!  did make\nUncapable of guilt.  Onward we pass\'d,\nWhere others skarf\'d in rugged folds of ice\nNot on their feet were turn\'d, but each revers\'d\n     There very weeping suffers not to weep;\nFor at their eyes grief seeking passage finds\nImpediment, and rolling inward turns\nFor increase of sharp anguish:  the first tears\nHang cluster\'d, and like crystal vizors show,\nUnder the socket brimming all the cup.\n     Now though the cold had from my face dislodg\'d\nEach feeling, as \'t were callous, yet me seem\'d\nSome breath of wind I felt.  \"Whence cometh this,\"\nSaid I, \"my master?  Is not here below\nAll vapour quench\'d?\"--\"\'Thou shalt be speedily,\"\nHe answer\'d, \"where thine eye shall tell thee whence\nThe cause descrying of this airy shower.\"\n     Then cried out one in the chill crust who mourn\'d:\n\"O souls so cruel!  that the farthest post\nHath been assign\'d you, from this face remove\nThe harden\'d veil, that I may vent the grief\nImpregnate at my heart, some little space\nEre it congeal again!\"  I thus replied:\n\"Say who thou wast, if thou wouldst have mine aid;\nAnd if I extricate thee not, far down\nAs to the lowest ice may I descend!\"\n     \"The friar Alberigo,\" answered he,\n\"Am I, who from the evil garden pluck\'d\nIts fruitage, and am here repaid, the date\nMore luscious for my fig.\"--\"Hah!\"  I exclaim\'d,\n\"Art thou too dead!\"--\"How in the world aloft\nIt fareth with my body,\" answer\'d he,\n\"I am right ignorant.  Such privilege\nHath Ptolomea, that ofttimes the soul\nDrops hither, ere by Atropos divorc\'d.\nAnd that thou mayst wipe out more willingly\nThe glazed tear-drops that o\'erlay mine eyes,\nKnow that the soul, that moment she betrays,\nAs I did, yields her body to a fiend\nWho after moves and governs it at will,\nTill all its time be rounded; headlong she\nFalls to this cistern.  And perchance above\nDoth yet appear the body of a ghost,\nWho here behind me winters.  Him thou know\'st,\nIf thou but newly art arriv\'d below.\nThe years are many that have pass\'d away,\nSince to this fastness Branca Doria ca");
    strcat(expected_filecontent, "me.\"\n     \"Now,\" answer\'d I, \"methinks thou mockest me,\nFor Branca Doria never yet hath died,\nBut doth all natural functions of a man,\nEats, drinks, and sleeps, and putteth raiment on.\"\n     He thus:  \"Not yet unto that upper foss\nBy th\' evil talons guarded, where the pitch\nTenacious boils, had Michael Zanche reach\'d,\nWhen this one left a demon in his stead\nIn his own body, and of one his kin,\nWho with him treachery wrought.  But now put forth\nThy hand, and ope mine eyes.\"  I op\'d them not.\nIll manners were best courtesy to him.\n     Ah Genoese!  men perverse in every way,\nWith every foulness stain\'d, why from the earth\nAre ye not cancel\'d?  Such an one of yours\nI with Romagna\'s darkest spirit found,\nAs for his doings even now in soul\nIs in Cocytus plung\'d, and yet doth seem\nIn body still alive upon the earth.\n\n\n\nCANTO XXXIV\n\n\"THE banners of Hell\'s Monarch do come forth\nTowards us; therefore look,\" so spake my guide,\n\"If thou discern him.\"  As, when");

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "PASS");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 13573, file);
                test_error(size == 13248, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 13248 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 13248);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 13248);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 15: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST15(void)
{
    // informacje o teście
    test_start(15, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(12731, 1);
                char expected_filecontent[12732] = "";

                strcat(expected_filecontent, "NOW was the day departing, and the air,\nImbrown\'d with shadows, from their toils releas\'d\nAll animals on earth; and I alone\nPrepar\'d myself the conflict to sustain,\nBoth of sad pity, and that perilous road,\nWhich my unerring memory shall retrace.\n     O Muses!  O high genius!  now vouchsafe\nYour aid!  O mind!  that all I saw hast kept\nSafe in a written record, here thy worth\nAnd eminent endowments come to proof.\n     I thus began:  \"Bard!  thou who art my guide,\nConsider well, if virtue be in me\nSufficient, ere to this high enterprise\nThou trust me.  Thou hast told that Silvius\' sire,\nYet cloth\'d in corruptible flesh, among\nTh\' immortal tribes had entrance, and was there\nSensible present.  Yet if heaven\'s great Lord,\nAlmighty foe to ill, such favour shew\'d,\nIn contemplation of the high effect,\nBoth what and who from him should issue forth,\nIt seems in reason\'s judgment well deserv\'d:\nSith he of Rome, and of Rome\'s empire wide,\nIn heaven\'s empyreal height was chosen sire:\nBoth which, if truth be spoken, were ordain\'d\nAnd \'stablish\'d for the holy place, where sits\nWho to great Peter\'s sacred chair succeeds.\nHe from this journey, in thy song renown\'d,\nLearn\'d things, that to his victory gave rise\nAnd to the papal robe.  In after-times\nThe chosen vessel also travel\'d there,\nTo bring us back assurance in that faith,\nWhich is the entrance to salvation\'s way.\nBut I, why should I there presume?  or who\nPermits it?  not, Aeneas I nor Paul.\nMyself I deem not worthy, and none else\nWill deem me.  I, if on this voyage then\nI venture, fear it will in folly end.\nThou, who art wise, better my meaning know\'st,\nThan I can speak.\"  As one, who unresolves\nWhat he hath late resolv\'d, and with new thoughts\nChanges his purpose, from his first intent\nRemov\'d; e\'en such was I on that dun coast,\nWasting in thought my enterprise, at first\nSo eagerly embrac\'d.  \"If right thy words\nI scan,\" replied that shade magnanimous,\n\"Thy soul is by vile fear assail\'d, which oft\nSo overcasts a man, that he recoils\nFrom noblest resolution, like a beast\nAt some false semblance in the twilight gloom.\nThat from this terror thou mayst free thyself,\nI will instruct thee why I came, and what\nI heard in that same instant, when for thee\nGrief touch\'d me first.  I was among the tribe,\nWho rest suspended, when a dame, so blest\nAnd lovely, I besought her to command,\nCall\'d me; her eyes were brighter than the star\nOf day; and she with gentle voice and soft\nAngelically tun\'d her speech address\'d:\n\"O courteous shade of Mantua!  thou whose fame\nYet lives, and shall live long as nature lasts!\nA friend, not of my fortune but myself,\nOn the wide desert in his road has met\nHindrance so great, that he through fear has turn\'d.\nNow much I dread lest he past help have stray\'d,\nAnd I be ris\'n too late for his relief,\nFrom what in heaven of him I heard.  Speed now,\nAnd by thy eloquent persuasive tongue,\nAnd by all means for his deliverance meet,\nAssist him.  So to me will comfort spring.\nI who now bid thee on this errand forth\nAm Beatrice; from a place I come\n\n(Note:  Beatrice.  I use this word, as it is\npronounced in the Italian, as consisting of four\nsyllables, of which the third is a long one.)\n\nRevisited with joy.  Love brought me thence,\nWho prompts my speech.  When in my Master\'s sight\nI stand, thy praise to him I oft will tell.\"\n     She then was silent, and I thus began:\n\"O Lady!  by whose influence alone,\nMankind excels whatever is contain\'d\nWithin that heaven which hath the smallest orb,\nSo thy command delights me, that to obey,\nIf it were done already, would seem late.\nNo need hast thou farther to speak thy will;\nYet tell the reason, why thou art not loth\nTo leave that ample space, where to return\nThou burnest, for this centre here beneath.\"\n     She then:  \"Since thou so deeply wouldst inquire,\nI will instruct thee briefly, why no dread\nHinders my entrance here.  Those things alone\nAre to be fear\'d, whence evil may proceed,\nNone else, for none are terrible beside.\nI am so fram\'d by God, thanks to his grace!\nThat any suff\'rance of your misery\nTouches me not, nor flame of tha");
    strcat(expected_filecontent, "t fierce fire\nAssails me.  In high heaven a blessed dame\nBesides, who mourns with such effectual grief\nThat hindrance, which I send thee to remove,\nThat God\'s stern judgment to her will inclines.\nTo Lucia calling, her she thus bespake:\n\"Now doth thy faithful servant need thy aid\nAnd I commend him to thee.\"  At her word\nSped Lucia, of all cruelty the foe,\nAnd coming to the place, where I abode\nSeated with Rachel, her of ancient days,\nShe thus address\'d me: \"Thou true praise of God!\nBeatrice!  why is not thy succour lent\nTo him, who so much lov\'d thee, as to leave\nFor thy sake all the multitude admires?\nDost thou not hear how pitiful his wail,\nNor mark the death, which in the torrent flood,\nSwoln mightier than a sea, him struggling holds?\"\nNe\'er among men did any with such speed\nHaste to their profit, flee from their annoy,\nAs when these words were spoken, I came here,\nDown from my blessed seat, trusting the force\nOf thy pure eloquence, which thee, and all\nWho well have mark\'d it, into honour brings.\"\n     \"When she had ended, her bright beaming eyes\nTearful she turn\'d aside; whereat I felt\nRedoubled zeal to serve thee.  As she will\'d,\nThus am I come: I sav\'d thee from the beast,\nWho thy near way across the goodly mount\nPrevented.  What is this comes o\'er thee then?\nWhy, why dost thou hang back?  why in thy breast\nHarbour vile fear?  why hast not courage there\nAnd noble daring?  Since three maids so blest\nThy safety plan, e\'en in the court of heaven;\nAnd so much certain good my words forebode.\"\n     As florets, by the frosty air of night\nBent down and clos\'d, when day has blanch\'d their leaves,\nRise all unfolded on their spiry stems;\nSo was my fainting vigour new restor\'d,\nAnd to my heart such kindly courage ran,\nThat I as one undaunted soon replied:\n\"O full of pity she, who undertook\nMy succour!  and thou kind who didst perform\nSo soon her true behest!  With such desire\nThou hast dispos\'d me to renew my voyage,\nThat my first purpose fully is resum\'d.\nLead on: one only will is in us both.\nThou art my guide, my master thou, and lord.\"\n     So spake I; and when he had onward mov\'d,\nI enter\'d on the deep and woody way.\n\n\n\nCANTO III\n\n\"THROUGH me you pass into the city of woe:\nThrough me you pass into eternal pain:\nThrough me among the people lost for aye.\nJustice the founder of my fabric mov\'d:\nTo rear me was the task of power divine,\nSupremest wisdom, and primeval love.\nBefore me things create were none, save things\nEternal, and eternal I endure.\nAll hope abandon ye who enter here.\"\n     Such characters in colour dim I mark\'d\nOver a portal\'s lofty arch inscrib\'d:\nWhereat I thus: \"Master, these words import\nHard meaning.\"  He as one prepar\'d replied:\n\"Here thou must all distrust behind thee leave;\nHere be vile fear extinguish\'d. We are come\nWhere I have told thee we shall see the souls\nTo misery doom\'d, who intellectual good\nHave lost.\"  And when his hand he had stretch\'d forth\nTo mine, with pleasant looks, whence I was cheer\'d,\nInto that secret place he led me on.\n     Here sighs with lamentations and loud moans\nResounded through the air pierc\'d by no star,\nThat e\'en I wept at entering.  Various tongues,\nHorrible languages, outcries of woe,\nAccents of anger, voices deep and hoarse,\nWith hands together smote that swell\'d the sounds,\nMade up a tumult, that for ever whirls\nRound through that air with solid darkness stain\'d,\nLike to the sand that in the whirlwind flies.\n     I then, with error yet encompass\'d, cried:\n\"O master!  What is this I hear?  What race\nAre these, who seem so overcome with woe?\"\n     He thus to me: \"This miserable fate\nSuffer the wretched souls of those, who liv\'d\nWithout or praise or blame, with that ill band\nOf angels mix\'d, who nor rebellious prov\'d\nNor yet were true to God, but for themselves\nWere only.  From his bounds Heaven drove them forth,\nNot to impair his lustre, nor the depth\nOf Hell receives them, lest th\' accursed tribe\nShould glory thence with exultation vain.\"\n     I then: \"Master!  what doth aggrieve them thus,\nThat they lament so loud?\"  He straight replied:\n\"That will I tell thee briefl");
    strcat(expected_filecontent, "y.  These of death\nNo hope may entertain: and their blind life\nSo meanly passes, that all other lots\nThey envy.  Fame of them the world hath none,\nNor suffers; mercy and justice scorn them both.\nSpeak not of them, but look, and pass them by.\"\n     And I, who straightway look\'d, beheld a flag,\nWhich whirling ran around so rapidly,\nThat it no pause obtain\'d: and following came\nSuch a long train of spirits, I should ne\'er\nHave thought, that death so many had despoil\'d.\n     When some of these I recogniz\'d, I saw\nAnd knew the shade of him, who to base fear\nYielding, abjur\'d his high estate.  Forthwith\nI understood for certain this the tribe\nOf those ill spirits both to God displeasing\nAnd to his foes.  These wretches, who ne\'er lived,\nWent on in nakedness, and sorely stung\nBy wasps and hornets, which bedew\'d their cheeks\nWith blood, that mix\'d with tears dropp\'d to their feet,\nAnd by disgustful worms was gather\'d there.\n     Then looking farther onwards I beheld\nA throng upon the shore of a great stream:\nWhereat I thus: \"Sir!  grant me now to know\nWhom here we view, and whence impell\'d they seem\nSo eager to pass o\'er, as I discern\nThrough the blear light?\"  He thus to me in few:\n\"This shalt thou know, soon as our steps arrive\nBeside the woeful tide of Acheron.\"\n     Then with eyes downward cast and fill\'d with shame,\nFearing my words offensive to his ear,\nTill we had reach\'d the river, I from speech\nAbstain\'d.  And lo!  toward us in a bark\nComes on an old man hoary white with eld,\nCrying, \"Woe to you wicked spirits!  hope not\nEver to see the sky again.  I come\nTo take you to the other shore across,\nInto eternal darkness, there to dwell\nIn fierce heat and in ice.  And thou, who there\nStandest, live spirit!  get thee hence, and leave\nThese who are dead.\"  But soon as he beheld\nI left them not, \"By other way,\" said he,\n\"By other haven shalt thou come to shore,\nNot by this passage; thee a nimbler boat\nMust carry.\"  Then to him thus spake my guide:\n\"Charon!  thyself torment not: so \'t is will\'d,\nWhere will and power are one: ask thou no more.\"\n     Straightway in silence fell the shaggy cheeks\nOf him the boatman o\'er the livid lake,\nAround whose eyes glar\'d wheeling flames.  Meanwhile\nThose spirits, faint and naked, color chang\'d,\nAnd gnash\'d their teeth, soon as the cruel words\nThey heard.  God and their parents they blasphem\'d,\nThe human kind, the place, the time, and seed\nThat did engender them and give them birth.\n     Then all together sorely wailing drew\nTo the curs\'d strand, that every man must pass\nWho fears not God.  Charon, demoniac form,\nWith eyes of burning coal, collects them all,\nBeck\'ning, and each, that lingers, with his oar\nStrikes.  As fall off the light autumnal leaves,\nOne still another following, till the bough\nStrews all its honours on the earth beneath;\nE\'en in like manner Adam\'s evil brood\nCast themselves one by one down from the shore,\nEach at a beck, as falcon at his call.\n     Thus go they over through the umber\'d wave,\nAnd ever they on the opposing bank\nBe landed, on this side another throng\nStill gathers.  \"Son,\" thus spake the courteous guide,\n\"Those, who die subject to the wrath of God,\nAll here together come from every clime,\nAnd to o\'erpass the river are not loth:\nFor so heaven\'s justice goads them on, that fear\nIs turn\'d into desire.  Hence ne\'er hath past\nGood spirit.  If of thee Charon complain,\nNow mayst thou know the import of his words.\"\n     This said, the gloomy region trembling shook\nSo terribly, that yet with clammy dews\nFear chills my brow.  The sad earth gave a blast,\nThat, lightening, shot forth a vermilion flame,\nWhich all my senses conquer\'d quite, and I\nDown dropp\'d, as one with sudden slumber seiz\'d.\n\n\n\nCANTO IV\n\nBROKE the deep slumber in my brain a crash\nOf heavy thunder, that I shook myself,\nAs one by main force rous\'d.  Risen upright,\nMy rested eyes I mov\'d around, and search\'d\nWith fixed ken to know what place it was,\nWherein I stood.  For certain on the brink\nI found me of the lamentable vale,\nThe dread abyss, that joins a thund\'rous sound\nOf plaints innumerable.  Dark and d");
    strcat(expected_filecontent, "eep,\nAnd thick with clouds o\'erspread, mine eye in vain\nExplor\'d its bottom, nor could aught discern.\n     \"Now let us to the blind world there beneath\nDescend;\" the bard began all pale of look:\n\"I go the first, and thou shalt follow next.\"\n     Then I his alter\'d hue perceiving, thus:\n\"How may I speed, if thou yieldest to dread,\nWho still art wont to comfort me in doubt?\"\n     He then:  \"The anguish of that race below\nWith pity stains my che");

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "WEEK");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 13025, file);
                test_error(size == 12731, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 12731 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 12731);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 12731);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 16: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST16(void)
{
    // informacje o teście
    test_start(16, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(6348, 1);
                char expected_filecontent[6349] = "";

                strcat(expected_filecontent, " that gate\nWe enter\'d first, whose threshold is to none\nDenied, nought else so worthy of regard,\nAs is this river, has thine eye discern\'d,\nO\'er which the flaming volley all is quench\'d.\"\n     So spake my guide; and I him thence besought,\nThat having giv\'n me appetite to know,\nThe food he too would give, that hunger crav\'d.\n     \"In midst of ocean,\" forthwith he began,\n\"A desolate country lies, which Crete is nam\'d,\nUnder whose monarch in old times the world\nLiv\'d pure and chaste.  A mountain rises there,\nCall\'d Ida, joyous once with leaves and streams,\nDeserted now like a forbidden thing.\nIt was the spot which Rhea, Saturn\'s spouse,\nChose for the secret cradle of her son;\nAnd better to conceal him, drown\'d in shouts\nHis infant cries.  Within the mount, upright\nAn ancient form there stands and huge, that turns\nHis shoulders towards Damiata, and at Rome\nAs in his mirror looks.  Of finest gold\nHis head is shap\'d, pure silver are the breast\nAnd arms; thence to the middle is of brass.\nAnd downward all beneath well-temper\'d steel,\nSave the right foot of potter\'s clay, on which\nThan on the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to the lowest depth of all,\nForm there Cocytus, of whose lake (thyself\nShall see it) I here give thee no account.\"\n     Then I to him:  \"If from our world this sluice\nBe thus deriv\'d; wherefore to us but now\nAppears it at this edge?\"  He straight replied:\n\"The place, thou know\'st, is round; and though great part\nThou have already pass\'d, still to the left\nDescending to the nethermost, not yet\nHast thou the circuit made of the whole orb.\nWherefore if aught of new to us appear,\nIt needs not bring up wonder in thy looks.\"\n     Then I again inquir\'d:  \"Where flow the streams\nOf Phlegethon and Lethe? for of one\nThou tell\'st not, and the other of that shower,\nThou say\'st, is form\'d.\"  He answer thus return\'d:\n\"Doubtless thy questions all well pleas\'d I hear.\nYet the red seething wave might have resolv\'d\nOne thou proposest.  Lethe thou shalt see,\nBut not within this hollow, in the place,\nWhither to lave themselves the spirits go,\nWhose blame hath been by penitence remov\'d.\"\nHe added:  \"Time is now we quit the wood.\nLook thou my steps pursue:  the margins give\nSafe passage, unimpeded by the flames;\nFor over them all vapour is extinct.\"\n\n\n\nCANTO XV\n\nOne of the solid margins bears us now\nEnvelop\'d in the mist, that from the stream\nArising, hovers o\'er, and saves from fire\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the mounds,\nSo fram\'d, though not in height or bulk to these\nMade equal, by the master, whosoe\'er\nHe was, that rais\'d them here.  We from the wood\nWere not so far remov\'d, that turning round\nI might not have discern\'d it, when we met\nA troop of spirits, who came beside the pier.\n     They each one ey\'d us, as at eventide\nOne eyes another under a new moon,\nAnd toward us sharpen\'d their sight as keen,\nAs an old tailor at his needle\'s eye.\n     Thus narrowly explor\'d by all the tribe,\nI was agniz\'d of one, who by the skirt\nCaught me, and cried, \"What wonder have we here!\"\n     And I, when he to me outstretch\'d his arm,\nIntently fix\'d my ken on his parch\'d looks,\nThat although smirch\'d with fire, they hinder\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent");
    strcat(expected_filecontent, ";\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefore on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path descend to tread\nOn equal ground with him, but held my head\nBent down, as one who walks in reverent guise.\n     \"What chance or destiny,\" thus be began,\n\"Ere the last day conducts thee here below?\nAnd who is this, that shows to thee the way?\"\n     \"There up aloft,\" I answer\'d, \"in the life\nSerene, I wander\'d in a valley lost,\nBefore mine age had to its fullness reach\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d, and now strikes full upon my heart\nThe dear, benign, paternal image, such\nAs thine was, when so lately thou didst teach me\nThe way for man to win eternity;\nAnd how I priz\'d t");

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "FIT.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6521, file);
                test_error(size == 6348, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6348 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6348);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6348);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 17: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST17(void)
{
    // informacje o teście
    test_start(17, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(6363, 1);
                char expected_filecontent[6364] = "";

                strcat(expected_filecontent, "emons on our way we went;\nAh fearful company!  but in the church\nWith saints, with gluttons at the tavern\'s mess.\n     Still earnest on the pitch I gaz\'d, to mark\nAll things whate\'er the chasm contain\'d, and those\nWho burn\'d within.  As dolphins, that, in sign\nTo mariners, heave high their arched backs,\nThat thence forewarn\'d they may advise to save\nTheir threaten\'d vessels; so, at intervals,\nTo ease the pain his back some sinner show\'d,\nThen hid more nimbly than the lightning glance.\n     E\'en as the frogs, that of a wat\'ry moat\nStand at the brink, with the jaws only out,\nTheir feet and of the trunk all else concealed,\nThus on each part the sinners stood, but soon\nAs Barbariccia was at hand, so they\nDrew back under the wave.  I saw, and yet\nMy heart doth stagger, one, that waited thus,\nAs it befalls that oft one frog remains,\nWhile the next springs away:  and Graffiacan,\nWho of the fiends was nearest, grappling seiz\'d\nHis clotted locks, and dragg\'d him sprawling up,\nThat he appear\'d to me an otter.  Each\nAlready by their names I knew, so well\nWhen they were chosen, I observ\'d, and mark\'d\nHow one the other call\'d. \"O Rubicant!\nSee that his hide thou with thy talons flay,\"\nShouted together all the cursed crew.\n     Then I:  \"Inform thee, master!  if thou may,\nWhat wretched soul is this, on whom their hand\nHis foes have laid.\"  My leader to his side\nApproach\'d, and whence he came inquir\'d, to whom\nWas answer\'d thus:  \"Born in Navarre\'s domain\nMy mother plac\'d me in a lord\'s retinue,\nFor she had borne me to a losel vile,\nA spendthrift of his substance and himself.\nThe good king Thibault after that I serv\'d,\nTo peculating here my thoughts were turn\'d,\nWhereof I give account in this dire heat.\"\n     Straight Ciriatto, from whose mouth a tusk\nIssued on either side, as from a boar,\nRipt him with one of these.  \'Twixt evil claws\nThe mouse had fall\'n:  but Barbariccia cried,\nSeizing him with both arms:  \"Stand thou apart,\nWhile I do fix him on my prong transpierc\'d.\"\nThen added, turning to my guide his face,\n\"Inquire of him, if more thou wish to learn,\nEre he again be rent.\"  My leader thus:\n\"Then tell us of the partners in thy guilt;\nKnowest thou any sprung of Latian land\nUnder the tar?\"--\"I parted,\" he replied,\n\"But now from one, who sojourn\'d not far thence;\nSo were I under shelter now with him!\nNor hook nor talon then should scare me more.\"--.\n     \"Too long we suffer,\" Libicocco cried,\nThen, darting forth a prong, seiz\'d on his arm,\nAnd mangled bore away the sinewy part.\nHim Draghinazzo by his thighs beneath\nWould next have caught, whence angrily their chief,\nTurning on all sides round, with threat\'ning brow\nRestrain\'d them.  When their strife a little ceas\'d,\nOf him, who yet was gazing on his wound,\nMy teacher thus without delay inquir\'d:\n\"Who was the spirit, from whom by evil hap\nParting, as thou has told, thou cam\'st to shore?\"--\n     \"It was the friar Gomita,\" he rejoin\'d,\n\"He of Gallura, vessel of all guile,\nWho had his master\'s enemies in hand,\nAnd us\'d them so that they commend him well.\nMoney he took, and them at large dismiss\'d.\nSo he reports:  and in each other charge\nCommitted to his keeping, play\'d the part\nOf barterer to the height:   with him doth herd\nThe chief of Logodoro, Michel Zanche.\nSardinia is a theme, whereof their tongue\nIs never weary.  Out! alas! behold\nThat other, how he grins!  More would I say,\nBut tremble lest he mean to maul me sore.\"\n     Their captain then to Farfarello turning,\nWho roll\'d his moony eyes in act to strike,\nRebuk\'d him thus:  \"Off! cursed bird! Avaunt!\"--\n     \"If ye desire to see or hear,\" he thus\nQuaking with dread resum\'d, \"or Tuscan spirits\nOr Lombard, I will cause them to appear.\nMeantime let these ill talons bate their fury,\nSo that no vengeance they may fear from them,\nAnd I, remaining in this self-same place,\nWill for myself but one, make sev\'n appear,\nWhen my shrill whistle shall be heard; for so\nOur custom is to call each other up.\"\n     Cagnazzo at that word deriding grinn\'d,\nThen wagg\'d the head and spake:  \"Hear his device,\nMischievous as he is, to plunge him down");
    strcat(expected_filecontent, ".\"\n     Whereto he thus, who fail\'d not in rich store\nOf nice-wove toils; \" Mischief forsooth extreme,\nMeant only to procure myself more woe!\"\n     No longer Alichino then refrain\'d,\nBut thus, the rest gainsaying, him bespake:\n\"If thou do cast thee down, I not on foot\nWill chase thee, but above the pitch will beat\nMy plumes.  Quit we the vantage ground, and let\nThe bank be as a shield, that we may see\nIf singly thou prevail against us all.\"\n     Now, reader, of new sport expect to hear!\n     They each one turn\'d his eyes to the\' other shore,\nHe first, who was the hardest to persuade.\nThe spirit of Navarre chose well his time,\nPlanted his feet on land, and at one leap\nEscaping disappointed their resolve.\n     Them quick resentment stung, but him the most,\nWho was the cause of failure; in pursuit\nHe therefore sped, exclaiming;  \"Thou art caught.\"\n     But little it avail\'d:  terror outstripp\'d\nHis following flight:  the other plung\'d beneath,\nAnd he with upward pinion rais\'d his breast:\nE\'en thus the water-fowl, when she perceives\nThe falcon near, dives instant down, while he\nEnrag\'d and spent retires.  That mockery\nIn Calcabrina fury stirr\'d, who flew\nAfter him, with desire of strife inflam\'d;\nAnd, for the barterer had \'scap\'d, so turn\'d\nHis talons on his comrade. O\'er the dyke\nIn grapple close they join\'d; but the\' other prov\'d\nA goshawk able to rend well his foe;\nAnd in the boiling lake both fell.  The heat\nWas umpire soon between them, but in vain\nTo lift themselves they strove, so fast were glued\nTheir pennons.  Barbariccia, as the rest,\nThat chance lamenting, four in flight dispatch\'d\nFrom the\' other coast, with all their weapons arm\'d.\nThey, to their post on each side speedily\nDescending, stretch\'d their hooks toward the fiends,\nWho flounder\'d, inly burning from their scars:\nAnd we departing left them to that broil.\n\n\n\nCANTO XXIII\n\nIN silence and in solitude we went,\nOne first, the other following his steps,\nAs minor friars journeying on their road.\n     The present fray had turn\'d my thoughts to muse\nUpon old Aesop\'s fable, where he told\nWhat fate unto the mouse and frog befell.\nFor language hath not sounds more like in sense,\nThan are these chances, if the origin\nAnd end of each be heedfully compar\'d.\nAnd as one thought b");

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "ORDER.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6657, file);
                test_error(size == 6363, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6363 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6363);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6363);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 18: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST18(void)
{
    // informacje o teście
    test_start(18, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(1461, 1);
                char expected_filecontent[1462] = "";

                strcat(expected_filecontent, "mpts them,\nThey wait not for the motions of the will\nIn natures most sincere.  I did but smile,\nAs one who winks; and thereupon the shade\nBroke off, and peer\'d into mine eyes, where best\nOur looks interpret. \"So to good event\nMayst thou conduct such great emprize,\" he cried,\n\"Say, why across thy visage beam\'d, but now,\nThe lightning of a smile!\"  On either part\nNow am I straiten\'d; one conjures me speak,\nTh\' other to silence binds me: whence a sigh\nI utter, and the sigh is heard.  \"Speak on; \"\nThe teacher cried;  \"and do not fear to speak,\nBut tell him what so earnestly he asks.\"\nWhereon I thus:  \"Perchance, O ancient spirit!\nThou marvel\'st at my smiling. There is room\nFor yet more wonder.  He who guides my ken\nOn high, he is that Mantuan, led by whom\nThou didst presume of men arid gods to sing.\nIf other cause thou deem\'dst for which I smil\'d,\nLeave it as not the true one; and believe\nThose words, thou spak\'st of him, indeed the cause.\"\n     Now down he bent t\' embrace my teacher\'s feet;\nBut he forbade him:  \"Brother!  do it not:\nThou art a shadow, and behold\'st a shade.\"\nHe rising answer\'d thus:  \"Now hast thou prov\'d\nThe force and ardour of the love I bear thee,\nWhen I forget we are but things of air,\nAnd as a substance treat an empty shade.\"\n\n\n\nCANTO XXII\n\nNow we had left the angel, who had turn\'d\nTo the sixth circle our ascending step,\nOne gash from off my forehead raz\'d: while they,\nWhose wishes tend to justice, shouted forth:\n\"Bles");

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "CASE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 1843, file);
                test_error(size == 1461, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1461 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1461);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 1461);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 19: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST19(void)
{
    // informacje o teście
    test_start(19, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(914, 1);
                char expected_filecontent[915] = "";

                strcat(expected_filecontent, "e had tended still\nThe thread and cordwain; and too late repents.\n     \"See next the wretches, who the needle left,\nThe shuttle and the spindle, and became\nDiviners:  baneful witcheries they wrought\nWith images and herbs.  But onward now:\nFor now doth Cain with fork of thorns confine\nOn either hemisphere, touching the wave\nBeneath the towers of Seville.  Yesternight\nThe moon was round.  Thou mayst remember well:\nFor she good service did thee in the gloom\nOf the deep wood.\"  This said, both onward mov\'d.\n\n\n\nCANTO XXI\n\nTHUS we from bridge to bridge, with other talk,\nThe which my drama cares not to rehearse,\nPass\'d on; and to the summit reaching, stood\nTo view another gap, within the round\nOf Malebolge, other bootless pangs.\n     Marvelous darkness shadow\'d o\'er the place.\n     In the Venetians\' arsenal as boils\nThrough wintry months tenacious pitch, to smear\nTheir unsound vessels; for th\' inclement time");

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "FINALFIG.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 1111, file);
                test_error(size == 914, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 914 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 914);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 914);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 20: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST20(void)
{
    // informacje o teście
    test_start(20, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[10241] = "";

                strcat(expected_filecontent, "s Beatrice?\"--\"See her,\" she replied,\n\"Beneath the fresh leaf seated on its root.\nBehold th\' associate choir that circles her.\nThe others, with a melody more sweet\nAnd more profound, journeying to higher realms,\nUpon the Gryphon tend.\"  If there her words\nWere clos\'d, I know not; but mine eyes had now\nTa\'en view of her, by whom all other thoughts\nWere barr\'d admittance.  On the very ground\nAlone she sat, as she had there been left\nA guard upon the wain, which I beheld\nBound to the twyform beast.  The seven nymphs\nDid make themselves a cloister round about her,\nAnd in their hands upheld those lights secure\nFrom blast septentrion and the gusty south.\n     \"A little while thou shalt be forester here:\nAnd citizen shalt be forever with me,\nOf that true Rome, wherein Christ dwells a Roman\nTo profit the misguided world, keep now\nThine eyes upon the car; and what thou seest,\nTake heed thou write, returning to that place.\"\n     Thus Beatrice: at whose feet inclin\'d\nDevout, at her behest, my thought and eyes,\nI, as she bade, directed.  Never fire,\nWith so swift motion, forth a stormy cloud\nLeap\'d downward from the welkin\'s farthest bound,\nAs I beheld the bird of Jove descending\nPounce on the tree, and, as he rush\'d, the rind,\nDisparting crush beneath him, buds much more\nAnd leaflets.  On the car with all his might\nHe struck, whence, staggering like a ship, it reel\'d,\nAt random driv\'n, to starboard now, o\'ercome,\nAnd now to larboard, by the vaulting waves.\n     Next springing up into the chariot\'s womb\nA fox I saw, with hunger seeming pin\'d\nOf all good food.  But, for his ugly sins\nThe saintly maid rebuking him, away\nScamp\'ring he turn\'d, fast as his hide-bound corpse\nWould bear him.  Next, from whence before he came,\nI saw the eagle dart into the hull\nO\' th\' car, and leave it with his feathers lin\'d;\nAnd then a voice, like that which issues forth\nFrom heart with sorrow riv\'d, did issue forth\nFrom heav\'n, and, \"O poor bark of mine!\" it cried,\n\"How badly art thou freighted!\"  Then, it seem\'d,\nThat the earth open\'d between either wheel,\nAnd I beheld a dragon issue thence,\nThat through the chariot fix\'d his forked train;\nAnd like a wasp that draggeth back the sting,\nSo drawing forth his baleful train, he dragg\'d\nPart of the bottom forth, and went his way\nExulting.  What remain\'d, as lively turf\nWith green herb, so did clothe itself with plumes,\nWhich haply had with purpose chaste and kind\nBeen offer\'d; and therewith were cloth\'d the wheels,\nBoth one and other, and the beam, so quickly\nA sigh were not breath\'d sooner.  Thus transform\'d,\nThe holy structure, through its several parts,\nDid put forth heads, three on the beam, and one\nOn every side; the first like oxen horn\'d,\nBut with a single horn upon their front\nThe four.  Like monster sight hath never seen.\nO\'er it methought there sat, secure as rock\nOn mountain\'s lofty top, a shameless whore,\nWhose ken rov\'d loosely round her.  At her side,\nAs \'t were that none might bear her off, I saw\nA giant stand; and ever, and anon\nThey mingled kisses.  But, her lustful eyes\nChancing on me to wander, that fell minion\nScourg\'d her from head to foot all o\'er; then full\nOf jealousy, and fierce with rage, unloos\'d\nThe monster, and dragg\'d on, so far across\nThe forest, that from me its shades alone\nShielded the harlot and the new-form\'d brute.\n\n\n\nCANTO XXXIII\n\n\"The heathen, Lord!  are come!\" responsive thus,\nThe trinal now, and now the virgin band\nQuaternion, their sweet psalmody began,\nWeeping; and Beatrice listen\'d, sad\nAnd sighing, to the song\', in such a mood,\nThat Mary, as she stood beside the cross,\nWas scarce more chang\'d.  But when they gave her place\nTo speak, then, risen upright on her feet,\nShe, with a colour glowing bright as fire,\nDid answer: \"Yet a little while, and ye\nShall see me not; and, my beloved sisters,\nAgain a little while, and ye shall see me.\"\n     Before her then she marshall\'d all the seven,\nAnd, beck\'ning only motion\'d me, the dame,\nAnd that remaining sage, to follow her.\n     So on she pass\'d; and had not set, I ween,\nHer tenth step to the ground, when with mine eyes\nHer ");
    strcat(expected_filecontent, "eyes encounter\'d; and, with visage mild,\n\"So mend thy pace,\" she cried, \"that if my words\nAddress thee, thou mayst still be aptly plac\'d\nTo hear them.\"  Soon as duly to her side\nI now had hasten\'d:  \"Brother!\" she began,\n\"Why mak\'st thou no attempt at questioning,\nAs thus we walk together?\"  Like to those\nWho, speaking with too reverent an awe\nBefore their betters, draw not forth the voice\nAlive unto their lips, befell me shell\nThat I in sounds imperfect thus began:\n\"Lady!  what I have need of, that thou know\'st,\nAnd what will suit my need.\"  She answering thus:\n\"Of fearfulness and shame, I will, that thou\nHenceforth do rid thee: that thou speak no more,\nAs one who dreams.  Thus far be taught of me:\nThe vessel, which thou saw\'st the serpent break,\nWas and is not: let him, who hath the blame,\nHope not to scare God\'s vengeance with a sop.\nWithout an heir for ever shall not be\nThat eagle, he, who left the chariot plum\'d,\nWhich monster made it first and next a prey.\nPlainly I view, and therefore speak, the stars\nE\'en now approaching, whose conjunction, free\nFrom all impediment and bar, brings on\nA season, in the which, one sent from God,\n(Five hundred, five, and ten, do mark him out)\nThat foul one, and th\' accomplice of her guilt,\nThe giant, both shall slay.  And if perchance\nMy saying, dark as Themis or as Sphinx,\nFail to persuade thee, (since like them it foils\nThe intellect with blindness) yet ere long\nEvents shall be the Naiads, that will solve\nThis knotty riddle, and no damage light\nOn flock or field.  Take heed; and as these words\nBy me are utter\'d, teach them even so\nTo those who live that life, which is a race\nTo death: and when thou writ\'st them, keep in mind\nNot to conceal how thou hast seen the plant,\nThat twice hath now been spoil\'d.  This whoso robs,\nThis whoso plucks, with blasphemy of deed\nSins against God, who for his use alone\nCreating hallow\'d it.  For taste of this,\nIn pain and in desire, five thousand years\nAnd upward, the first soul did yearn for him,\nWho punish\'d in himself the fatal gust.\n     \"Thy reason slumbers, if it deem this height\nAnd summit thus inverted of the plant,\nWithout due cause: and were not vainer thoughts,\nAs Elsa\'s numbing waters, to thy soul,\nAnd their fond pleasures had not dyed it dark\nAs Pyramus the mulberry, thou hadst seen,\nIn such momentous circumstance alone,\nGod\'s equal justice morally implied\nIn the forbidden tree.  But since I mark thee\nIn understanding harden\'d into stone,\nAnd, to that hardness, spotted too and stain\'d,\nSo that thine eye is dazzled at my word,\nI will, that, if not written, yet at least\nPainted thou take it in thee, for the cause,\nThat one brings home his staff inwreath\'d with palm.\n     \"I thus:  \"As wax by seal, that changeth not\nIts impress, now is stamp\'d my brain by thee.\nBut wherefore soars thy wish\'d-for speech so high\nBeyond my sight, that loses it the more,\nThe more it strains to reach it?\" --\"To the end\nThat thou mayst know,\" she answer\'d straight, \"the school,\nThat thou hast follow\'d; and how far behind,\nWhen following my discourse, its learning halts:\nAnd mayst behold your art, from the divine\nAs distant, as the disagreement is\n\'Twixt earth and heaven\'s most high and rapturous orb.\"\n     \"I not remember,\" I replied, \"that e\'er\nI was estrang\'d from thee, nor for such fault\nDoth conscience chide me.\"  Smiling she return\'d:\n\"If thou canst, not remember, call to mind\nHow lately thou hast drunk of Lethe\'s wave;\nAnd, sure as smoke doth indicate a flame,\nIn that forgetfulness itself conclude\nBlame from thy alienated will incurr\'d.\nFrom henceforth verily my words shall be\nAs naked as will suit them to appear\nIn thy unpractis\'d view.\"  More sparkling now,\nAnd with retarded course the sun possess\'d\nThe circle of mid-day, that varies still\nAs th\' aspect varies of each several clime,\nWhen, as one, sent in vaward of a troop\nFor escort, pauses, if perchance he spy\nVestige of somewhat strange and rare: so paus\'d\nThe sev\'nfold band, arriving at the verge\nOf a dun umbrage hoar, such as is seen,\nBeneath green leaves and gloomy branches, oft\nTo overbrow a bleak ");
    strcat(expected_filecontent, "and alpine cliff.\nAnd, where they stood, before them, as it seem\'d,\nTigris and Euphrates both beheld,\nForth from one fountain issue; and, like friends,\nLinger at parting. \"O enlight\'ning beam!\nO glory of our kind!  beseech thee say\nWhat water this, which from one source deriv\'d\nItself removes to distance from itself?\"\n     To such entreaty answer thus was made:\n\"Entreat Matilda, that she teach thee this.\"\n     And here, as one, who clears himself of blame\nImputed, the fair dame return\'d:  \"Of me\nHe this and more hath learnt; and I am safe\nThat Lethe\'s water hath not hid it from him.\"\n     And Beatrice:  \"Some more pressing care\nThat oft the memory \'reeves, perchance hath made\nHis mind\'s eye dark.  But lo!  where Eunoe cows!\nLead thither; and, as thou art wont, revive\nHis fainting virtue.\"  As a courteous spirit,\nThat proffers no excuses, but as soon\nAs he hath token of another\'s will,\nMakes it his own; when she had ta\'en me, thus\nThe lovely maiden mov\'d her on, and call\'d\nTo Statius with an air most lady-like:\n\"Come thou with him.\"  Were further space allow\'d,\nThen, Reader, might I sing, though but in part,\nThat beverage, with whose sweetness I had ne\'er\nBeen sated.  But, since all the leaves are full,\nAppointed for this second strain, mine art\nWith warning bridle checks me.  I return\'d\nFrom the most holy wave, regenerate,\nIf \'en as new plants renew\'d with foliage new,\nPure and made apt for mounting to the stars.\n\n\n\nNOTES TO PURGATORY\n\nCANTO I\n\nVerse 1.  O\'er better waves.]  Berni, Orl. Inn. L 2. c. i.\nPer correr maggior acqua alza le vele,\nO debil navicella del mio ingegno.\n\nv. 11.  Birds of chattering note.]  For the fable of the\ndaughters of Pierus, who challenged the muses to sing, and were\nby them\nchanged into magpies, see Ovid, Met. 1. v. fab. 5.\n\nv. 19.  Planet.]  Venus.\n\nv. 20.  Made all the orient laugh.]  Hence Chaucer, Knight\'s\nTale: And all the orisont laugheth of the sight.\n\nIt is sometimes read \"orient.\"\n\nv. 24.  Four stars.]  Symbolical of the four cardinal virtues,\nPrudence Justice, Fortitude, and T");

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "LIKE.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 10240; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 21: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST21(void)
{
    // informacje o teście
    test_start(21, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[13249] = "";

                strcat(expected_filecontent, ", if chance a passing cloud\nSo sail across, that opposite it hangs,\nSuch then Antaeus seem\'d, as at mine ease\nI mark\'d him stooping.  I were fain at times\nT\' have pass\'d another way.  Yet in th\' abyss,\nThat Lucifer with Judas low ingulfs,\nI,ightly he plac\'d us; nor there leaning stay\'d,\nBut rose as in a bark the stately mast.\n\n\n\nCANTO XXXII\n\nCOULD I command rough rhimes and hoarse, to suit\nThat hole of sorrow, o\'er which ev\'ry rock\nHis firm abutment rears, then might the vein\nOf fancy rise full springing:  but not mine\nSuch measures, and with falt\'ring awe I touch\nThe mighty theme; for to describe the depth\nOf all the universe, is no emprize\nTo jest with, and demands a tongue not us\'d\nTo infant babbling.  But let them assist\nMy song, the tuneful maidens, by whose aid\nAmphion wall\'d in Thebes, so with the truth\nMy speech shall best accord.  Oh ill-starr\'d folk,\nBeyond all others wretched!  who abide\nIn such a mansion, as scarce thought finds words\nTo speak of, better had ye here on earth\nBeen flocks or mountain goats.  As down we stood\nIn the dark pit beneath the giants\' feet,\nBut lower far than they, and I did gaze\nStill on the lofty battlement, a voice\nBespoke me thus:  \"Look how thou walkest.  Take\nGood heed, thy soles do tread not on the heads\nOf thy poor brethren.\"  Thereupon I turn\'d,\nAnd saw before and underneath my feet\nA lake, whose frozen surface liker seem\'d\nTo glass than water.  Not so thick a veil\nIn winter e\'er hath Austrian Danube spread\nO\'er his still course, nor Tanais far remote\nUnder the chilling sky.  Roll\'d o\'er that mass\nHad Tabernich or Pietrapana fall\'n,\nNot e\'en its rim had creak\'d. As peeps the frog\nCroaking above the wave, what time in dreams\nThe village gleaner oft pursues her toil,\nSo, to where modest shame appears, thus low\nBlue pinch\'d and shrin\'d in ice the spirits stood,\nMoving their teeth in shrill note like the stork.\nHis face each downward held; their mouth the cold,\nTheir eyes express\'d the dolour of their heart.\n     A space I look\'d around, then at my feet\nSaw two so strictly join\'d, that of their head\nThe very hairs were mingled.  \"Tell me ye,\nWhose bosoms thus together press,\" said I,\n\"Who are ye?\"  At that sound their necks they bent,\nAnd when their looks were lifted up to me,\nStraightway their eyes, before all moist within,\nDistill\'d upon their lips, and the frost bound\nThe tears betwixt those orbs and held them there.\nPlank unto plank hath never cramp clos\'d up\nSo stoutly.  Whence like two enraged goats\nThey clash\'d together; them such fury seiz\'d.\n     And one, from whom the cold both ears had reft,\nExclaim\'d, still looking downward: \"Why on us\nDost speculate so long?  If thou wouldst know\nWho are these two, the valley, whence his wave\nBisenzio slopes, did for its master own\nTheir sire Alberto, and next him themselves.\nThey from one body issued; and throughout\nCaina thou mayst search, nor find a shade\nMore worthy in congealment to be fix\'d,\nNot him, whose breast and shadow Arthur\'s land\nAt that one blow dissever\'d, not Focaccia,\nNo not this spirit, whose o\'erjutting head\nObstructs my onward view:  he bore the name\nOf Mascheroni:  Tuscan if thou be,\nWell knowest who he was:  and to cut short\nAll further question, in my form behold\nWhat once was Camiccione.  I await\nCarlino here my kinsman, whose deep guilt\nShall wash out mine.\"  A thousand visages\nThen mark\'d I, which the keen and eager cold\nHad shap\'d into a doggish grin; whence creeps\nA shiv\'ring horror o\'er me, at the thought\nOf those frore shallows.  While we journey\'d on\nToward the middle, at whose point unites\nAll heavy substance, and I trembling went\nThrough that eternal chillness, I know not\nIf will it were or destiny, or chance,\nBut, passing \'midst the heads, my foot did strike\nWith violent blow against the face of one.\n     \"Wherefore dost bruise me?\" weeping, he exclaim\'d,\n\"Unless thy errand be some fresh revenge\nFor Montaperto, wherefore troublest me?\"\n     I thus:  \"Instructor, now await me here,\nThat I through him may rid me of my doubt.\nThenceforth what haste thou wilt.\"  The teacher paus\'d,\nAnd to that shade I s");
    strcat(expected_filecontent, "pake, who bitterly\nStill curs\'d me in his wrath.  \"What art thou, speak,\nThat railest thus on others?\"  He replied:\n\"Now who art thou, that smiting others\' cheeks\nThrough Antenora roamest, with such force\nAs were past suff\'rance, wert thou living still?\"\n     \"And I am living, to thy joy perchance,\"\nWas my reply, \"if fame be dear to thee,\nThat with the rest I may thy name enrol.\"\n     \"The contrary of what I covet most,\"\nSaid he, \"thou tender\'st:  hence; nor vex me more.\nIll knowest thou to flatter in this vale.\"\n     Then seizing on his hinder scalp, I cried:\n\"Name thee, or not a hair shall tarry here.\"\n     \"Rend all away,\" he answer\'d, \"yet for that\nI will not tell nor show thee who I am,\nThough at my head thou pluck a thousand times.\"\n     Now I had grasp\'d his tresses, and stript off\nMore than one tuft, he barking, with his eyes\nDrawn in and downward, when another cried,\n\"What ails thee, Bocca?  Sound not loud enough\nThy chatt\'ring teeth, but thou must bark outright?\nWhat devil wrings thee?\"--\" Now,\" said I, \"be dumb,\nAccursed traitor!  to thy shame of thee\nTrue tidings will I bear.\"--\" Off,\" he replied,\n\"Tell what thou list; but as thou escape from hence\nTo speak of him whose tongue hath been so glib,\nForget not:  here he wails the Frenchman\'s gold.\n\'Him of Duera,\' thou canst say, \'I mark\'d,\nWhere the starv\'d sinners pine.\'  If thou be ask\'d\nWhat other shade was with them, at thy side\nIs Beccaria, whose red gorge distain\'d\nThe biting axe of Florence.  Farther on,\nIf I misdeem not, Soldanieri bides,\nWith Ganellon, and Tribaldello, him\nWho op\'d Faenza when the people slept.\"\n     We now had left him, passing on our way,\nWhen I beheld two spirits by the ice\nPent in one hollow, that the head of one\nWas cowl unto the other; and as bread\nIs raven\'d up through hunger, th\' uppermost\nDid so apply his fangs to th\' other\'s brain,\nWhere the spine joins it.  Not more furiously\nOn Menalippus\' temples Tydeus gnaw\'d,\nThan on that skull and on its garbage he.\n     \"O thou who show\'st so beastly sign of hate\n\'Gainst him thou prey\'st on, let me hear,\" said I\n\"The cause, on such condition, that if right\nWarrant thy grievance, knowing who ye are,\nAnd what the colour of his sinning was,\nI may repay thee in the world above,\nIf that, wherewith I speak be moist so long.\"\n\n\n\nCANTO XXXIII\n\nHIS jaws uplifting from their fell repast,\nThat sinner wip\'d them on the hairs o\' th\' head,\nWhich he behind had mangled, then began:\n\"Thy will obeying, I call up afresh\nSorrow past cure, which but to think of wrings\nMy heart, or ere I tell on\'t. But if words,\nThat I may utter, shall prove seed to bear\nFruit of eternal infamy to him,\nThe traitor whom I gnaw at, thou at once\nShalt see me speak and weep.  Who thou mayst be\nI know not, nor how here below art come:\nBut Florentine thou seemest of a truth,\nWhen I do hear thee.  Know I was on earth\nCount Ugolino, and th\' Archbishop he\nRuggieri.  Why I neighbour him so close,\nNow list.  That through effect of his ill thoughts\nIn him my trust reposing, I was ta\'en\nAnd after murder\'d, need is not I tell.\nWhat therefore thou canst not have heard, that is,\nHow cruel was the murder, shalt thou hear,\nAnd know if he have wrong\'d me.  A small grate\nWithin that mew, which for my sake the name\nOf famine bears, where others yet must pine,\nAlready through its opening sev\'ral moons\nHad shown me, when I slept the evil sleep,\nThat from the future tore the curtain off.\nThis one, methought, as master of the sport,\nRode forth to chase the gaunt wolf and his whelps\nUnto the mountain, which forbids the sight\nOf Lucca to the Pisan.  With lean brachs\nInquisitive and keen, before him rang\'d\nLanfranchi with Sismondi and Gualandi.\nAfter short course the father and the sons\nSeem\'d tir\'d and lagging, and methought I saw\nThe sharp tusks gore their sides.  When I awoke\nBefore the dawn, amid their sleep I heard\nMy sons (for they were with me) weep and ask\nFor bread.  Right cruel art thou, if no pang\nThou feel at thinking what my heart foretold;\nAnd if not now, why use thy tears to flow?\nNow had they waken\'d; and the hour drew near\nWhen they we");
    strcat(expected_filecontent, "re wont to bring us food; the mind\nOf each misgave him through his dream, and I\nHeard, at its outlet underneath lock\'d up\nThe\' horrible tower:  whence uttering not a word\nI look\'d upon the visage of my sons.\nI wept not:  so all stone I felt within.\nThey wept:  and one, my little Anslem, cried:\n\"Thou lookest so!  Father what ails thee?\"  Yet\nI shed no tear, nor answer\'d all that day\nNor the next night, until another sun\nCame out upon the world.  When a faint beam\nHad to our doleful prison made its way,\nAnd in four countenances I descry\'d\nThe image of my own, on either hand\nThrough agony I bit, and they who thought\nI did it through desire of feeding, rose\nO\' th\' sudden, and cried, \'Father, we should grieve\nFar less, if thou wouldst eat of us: thou gav\'st\nThese weeds of miserable flesh we wear,\nAnd do thou strip them off from us again.\'\nThen, not to make them sadder, I kept down\nMy spirit in stillness.  That day and the next\nWe all were silent.  Ah, obdurate earth!\nWhy open\'dst not upon us?  When we came\nTo the fourth day, then Geddo at my feet\nOutstretch\'d did fling him, crying, \'Hast no help\nFor me, my father!\'  \"There he died, and e\'en\nPlainly as thou seest me, saw I the three\nFall one by one \'twixt the fifth day and sixth:\nWhence I betook me now grown blind to grope\nOver them all, and for three days aloud\nCall\'d on them who were dead.  Then fasting got\nThe mastery of grief.\"  Thus having spoke,\nOnce more upon the wretched skull his teeth\nHe fasten\'d, like a mastiff\'s \'gainst the bone\nFirm and unyielding.  Oh thou Pisa!  shame\nOf all the people, who their dwelling make\nIn that fair region, where th\' Italian voice\nIs heard, since that thy neighbours are so slack\nTo punish, from their deep foundations rise\nCapraia and Gorgona, and dam up\nThe mouth of Arno, that each soul in thee\nMay perish in the waters!  What if fame\nReported that thy castles were betray\'d\nBy Ugolino, yet no right hadst thou\nTo stretch his children on the rack.  For them,\nBrigata, Ugaccione, and the pair\nOf gentle ones, of whom my song hath told,\nTheir tender years, thou modern Thebes!  did make\nUncapable of guilt.  Onward we pass\'d,\nWhere others skarf\'d in rugged folds of ice\nNot on their feet were turn\'d, but each revers\'d\n     There very weeping suffers not to weep;\nFor at their eyes grief seeking passage finds\nImpediment, and rolling inward turns\nFor increase of sharp anguish:  the first tears\nHang cluster\'d, and like crystal vizors show,\nUnder the socket brimming all the cup.\n     Now though the cold had from my face dislodg\'d\nEach feeling, as \'t were callous, yet me seem\'d\nSome breath of wind I felt.  \"Whence cometh this,\"\nSaid I, \"my master?  Is not here below\nAll vapour quench\'d?\"--\"\'Thou shalt be speedily,\"\nHe answer\'d, \"where thine eye shall tell thee whence\nThe cause descrying of this airy shower.\"\n     Then cried out one in the chill crust who mourn\'d:\n\"O souls so cruel!  that the farthest post\nHath been assign\'d you, from this face remove\nThe harden\'d veil, that I may vent the grief\nImpregnate at my heart, some little space\nEre it congeal again!\"  I thus replied:\n\"Say who thou wast, if thou wouldst have mine aid;\nAnd if I extricate thee not, far down\nAs to the lowest ice may I descend!\"\n     \"The friar Alberigo,\" answered he,\n\"Am I, who from the evil garden pluck\'d\nIts fruitage, and am here repaid, the date\nMore luscious for my fig.\"--\"Hah!\"  I exclaim\'d,\n\"Art thou too dead!\"--\"How in the world aloft\nIt fareth with my body,\" answer\'d he,\n\"I am right ignorant.  Such privilege\nHath Ptolomea, that ofttimes the soul\nDrops hither, ere by Atropos divorc\'d.\nAnd that thou mayst wipe out more willingly\nThe glazed tear-drops that o\'erlay mine eyes,\nKnow that the soul, that moment she betrays,\nAs I did, yields her body to a fiend\nWho after moves and governs it at will,\nTill all its time be rounded; headlong she\nFalls to this cistern.  And perchance above\nDoth yet appear the body of a ghost,\nWho here behind me winters.  Him thou know\'st,\nIf thou but newly art arriv\'d below.\nThe years are many that have pass\'d away,\nSince to this fastness Branca Doria ca");
    strcat(expected_filecontent, "me.\"\n     \"Now,\" answer\'d I, \"methinks thou mockest me,\nFor Branca Doria never yet hath died,\nBut doth all natural functions of a man,\nEats, drinks, and sleeps, and putteth raiment on.\"\n     He thus:  \"Not yet unto that upper foss\nBy th\' evil talons guarded, where the pitch\nTenacious boils, had Michael Zanche reach\'d,\nWhen this one left a demon in his stead\nIn his own body, and of one his kin,\nWho with him treachery wrought.  But now put forth\nThy hand, and ope mine eyes.\"  I op\'d them not.\nIll manners were best courtesy to him.\n     Ah Genoese!  men perverse in every way,\nWith every foulness stain\'d, why from the earth\nAre ye not cancel\'d?  Such an one of yours\nI with Romagna\'s darkest spirit found,\nAs for his doings even now in soul\nIs in Cocytus plung\'d, and yet doth seem\nIn body still alive upon the earth.\n\n\n\nCANTO XXXIV\n\n\"THE banners of Hell\'s Monarch do come forth\nTowards us; therefore look,\" so spake my guide,\n\"If thou discern him.\"  As, when");

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "PASS");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 13248; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 22: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST22(void)
{
    // informacje o teście
    test_start(22, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[12732] = "";

                strcat(expected_filecontent, "NOW was the day departing, and the air,\nImbrown\'d with shadows, from their toils releas\'d\nAll animals on earth; and I alone\nPrepar\'d myself the conflict to sustain,\nBoth of sad pity, and that perilous road,\nWhich my unerring memory shall retrace.\n     O Muses!  O high genius!  now vouchsafe\nYour aid!  O mind!  that all I saw hast kept\nSafe in a written record, here thy worth\nAnd eminent endowments come to proof.\n     I thus began:  \"Bard!  thou who art my guide,\nConsider well, if virtue be in me\nSufficient, ere to this high enterprise\nThou trust me.  Thou hast told that Silvius\' sire,\nYet cloth\'d in corruptible flesh, among\nTh\' immortal tribes had entrance, and was there\nSensible present.  Yet if heaven\'s great Lord,\nAlmighty foe to ill, such favour shew\'d,\nIn contemplation of the high effect,\nBoth what and who from him should issue forth,\nIt seems in reason\'s judgment well deserv\'d:\nSith he of Rome, and of Rome\'s empire wide,\nIn heaven\'s empyreal height was chosen sire:\nBoth which, if truth be spoken, were ordain\'d\nAnd \'stablish\'d for the holy place, where sits\nWho to great Peter\'s sacred chair succeeds.\nHe from this journey, in thy song renown\'d,\nLearn\'d things, that to his victory gave rise\nAnd to the papal robe.  In after-times\nThe chosen vessel also travel\'d there,\nTo bring us back assurance in that faith,\nWhich is the entrance to salvation\'s way.\nBut I, why should I there presume?  or who\nPermits it?  not, Aeneas I nor Paul.\nMyself I deem not worthy, and none else\nWill deem me.  I, if on this voyage then\nI venture, fear it will in folly end.\nThou, who art wise, better my meaning know\'st,\nThan I can speak.\"  As one, who unresolves\nWhat he hath late resolv\'d, and with new thoughts\nChanges his purpose, from his first intent\nRemov\'d; e\'en such was I on that dun coast,\nWasting in thought my enterprise, at first\nSo eagerly embrac\'d.  \"If right thy words\nI scan,\" replied that shade magnanimous,\n\"Thy soul is by vile fear assail\'d, which oft\nSo overcasts a man, that he recoils\nFrom noblest resolution, like a beast\nAt some false semblance in the twilight gloom.\nThat from this terror thou mayst free thyself,\nI will instruct thee why I came, and what\nI heard in that same instant, when for thee\nGrief touch\'d me first.  I was among the tribe,\nWho rest suspended, when a dame, so blest\nAnd lovely, I besought her to command,\nCall\'d me; her eyes were brighter than the star\nOf day; and she with gentle voice and soft\nAngelically tun\'d her speech address\'d:\n\"O courteous shade of Mantua!  thou whose fame\nYet lives, and shall live long as nature lasts!\nA friend, not of my fortune but myself,\nOn the wide desert in his road has met\nHindrance so great, that he through fear has turn\'d.\nNow much I dread lest he past help have stray\'d,\nAnd I be ris\'n too late for his relief,\nFrom what in heaven of him I heard.  Speed now,\nAnd by thy eloquent persuasive tongue,\nAnd by all means for his deliverance meet,\nAssist him.  So to me will comfort spring.\nI who now bid thee on this errand forth\nAm Beatrice; from a place I come\n\n(Note:  Beatrice.  I use this word, as it is\npronounced in the Italian, as consisting of four\nsyllables, of which the third is a long one.)\n\nRevisited with joy.  Love brought me thence,\nWho prompts my speech.  When in my Master\'s sight\nI stand, thy praise to him I oft will tell.\"\n     She then was silent, and I thus began:\n\"O Lady!  by whose influence alone,\nMankind excels whatever is contain\'d\nWithin that heaven which hath the smallest orb,\nSo thy command delights me, that to obey,\nIf it were done already, would seem late.\nNo need hast thou farther to speak thy will;\nYet tell the reason, why thou art not loth\nTo leave that ample space, where to return\nThou burnest, for this centre here beneath.\"\n     She then:  \"Since thou so deeply wouldst inquire,\nI will instruct thee briefly, why no dread\nHinders my entrance here.  Those things alone\nAre to be fear\'d, whence evil may proceed,\nNone else, for none are terrible beside.\nI am so fram\'d by God, thanks to his grace!\nThat any suff\'rance of your misery\nTouches me not, nor flame of tha");
    strcat(expected_filecontent, "t fierce fire\nAssails me.  In high heaven a blessed dame\nBesides, who mourns with such effectual grief\nThat hindrance, which I send thee to remove,\nThat God\'s stern judgment to her will inclines.\nTo Lucia calling, her she thus bespake:\n\"Now doth thy faithful servant need thy aid\nAnd I commend him to thee.\"  At her word\nSped Lucia, of all cruelty the foe,\nAnd coming to the place, where I abode\nSeated with Rachel, her of ancient days,\nShe thus address\'d me: \"Thou true praise of God!\nBeatrice!  why is not thy succour lent\nTo him, who so much lov\'d thee, as to leave\nFor thy sake all the multitude admires?\nDost thou not hear how pitiful his wail,\nNor mark the death, which in the torrent flood,\nSwoln mightier than a sea, him struggling holds?\"\nNe\'er among men did any with such speed\nHaste to their profit, flee from their annoy,\nAs when these words were spoken, I came here,\nDown from my blessed seat, trusting the force\nOf thy pure eloquence, which thee, and all\nWho well have mark\'d it, into honour brings.\"\n     \"When she had ended, her bright beaming eyes\nTearful she turn\'d aside; whereat I felt\nRedoubled zeal to serve thee.  As she will\'d,\nThus am I come: I sav\'d thee from the beast,\nWho thy near way across the goodly mount\nPrevented.  What is this comes o\'er thee then?\nWhy, why dost thou hang back?  why in thy breast\nHarbour vile fear?  why hast not courage there\nAnd noble daring?  Since three maids so blest\nThy safety plan, e\'en in the court of heaven;\nAnd so much certain good my words forebode.\"\n     As florets, by the frosty air of night\nBent down and clos\'d, when day has blanch\'d their leaves,\nRise all unfolded on their spiry stems;\nSo was my fainting vigour new restor\'d,\nAnd to my heart such kindly courage ran,\nThat I as one undaunted soon replied:\n\"O full of pity she, who undertook\nMy succour!  and thou kind who didst perform\nSo soon her true behest!  With such desire\nThou hast dispos\'d me to renew my voyage,\nThat my first purpose fully is resum\'d.\nLead on: one only will is in us both.\nThou art my guide, my master thou, and lord.\"\n     So spake I; and when he had onward mov\'d,\nI enter\'d on the deep and woody way.\n\n\n\nCANTO III\n\n\"THROUGH me you pass into the city of woe:\nThrough me you pass into eternal pain:\nThrough me among the people lost for aye.\nJustice the founder of my fabric mov\'d:\nTo rear me was the task of power divine,\nSupremest wisdom, and primeval love.\nBefore me things create were none, save things\nEternal, and eternal I endure.\nAll hope abandon ye who enter here.\"\n     Such characters in colour dim I mark\'d\nOver a portal\'s lofty arch inscrib\'d:\nWhereat I thus: \"Master, these words import\nHard meaning.\"  He as one prepar\'d replied:\n\"Here thou must all distrust behind thee leave;\nHere be vile fear extinguish\'d. We are come\nWhere I have told thee we shall see the souls\nTo misery doom\'d, who intellectual good\nHave lost.\"  And when his hand he had stretch\'d forth\nTo mine, with pleasant looks, whence I was cheer\'d,\nInto that secret place he led me on.\n     Here sighs with lamentations and loud moans\nResounded through the air pierc\'d by no star,\nThat e\'en I wept at entering.  Various tongues,\nHorrible languages, outcries of woe,\nAccents of anger, voices deep and hoarse,\nWith hands together smote that swell\'d the sounds,\nMade up a tumult, that for ever whirls\nRound through that air with solid darkness stain\'d,\nLike to the sand that in the whirlwind flies.\n     I then, with error yet encompass\'d, cried:\n\"O master!  What is this I hear?  What race\nAre these, who seem so overcome with woe?\"\n     He thus to me: \"This miserable fate\nSuffer the wretched souls of those, who liv\'d\nWithout or praise or blame, with that ill band\nOf angels mix\'d, who nor rebellious prov\'d\nNor yet were true to God, but for themselves\nWere only.  From his bounds Heaven drove them forth,\nNot to impair his lustre, nor the depth\nOf Hell receives them, lest th\' accursed tribe\nShould glory thence with exultation vain.\"\n     I then: \"Master!  what doth aggrieve them thus,\nThat they lament so loud?\"  He straight replied:\n\"That will I tell thee briefl");
    strcat(expected_filecontent, "y.  These of death\nNo hope may entertain: and their blind life\nSo meanly passes, that all other lots\nThey envy.  Fame of them the world hath none,\nNor suffers; mercy and justice scorn them both.\nSpeak not of them, but look, and pass them by.\"\n     And I, who straightway look\'d, beheld a flag,\nWhich whirling ran around so rapidly,\nThat it no pause obtain\'d: and following came\nSuch a long train of spirits, I should ne\'er\nHave thought, that death so many had despoil\'d.\n     When some of these I recogniz\'d, I saw\nAnd knew the shade of him, who to base fear\nYielding, abjur\'d his high estate.  Forthwith\nI understood for certain this the tribe\nOf those ill spirits both to God displeasing\nAnd to his foes.  These wretches, who ne\'er lived,\nWent on in nakedness, and sorely stung\nBy wasps and hornets, which bedew\'d their cheeks\nWith blood, that mix\'d with tears dropp\'d to their feet,\nAnd by disgustful worms was gather\'d there.\n     Then looking farther onwards I beheld\nA throng upon the shore of a great stream:\nWhereat I thus: \"Sir!  grant me now to know\nWhom here we view, and whence impell\'d they seem\nSo eager to pass o\'er, as I discern\nThrough the blear light?\"  He thus to me in few:\n\"This shalt thou know, soon as our steps arrive\nBeside the woeful tide of Acheron.\"\n     Then with eyes downward cast and fill\'d with shame,\nFearing my words offensive to his ear,\nTill we had reach\'d the river, I from speech\nAbstain\'d.  And lo!  toward us in a bark\nComes on an old man hoary white with eld,\nCrying, \"Woe to you wicked spirits!  hope not\nEver to see the sky again.  I come\nTo take you to the other shore across,\nInto eternal darkness, there to dwell\nIn fierce heat and in ice.  And thou, who there\nStandest, live spirit!  get thee hence, and leave\nThese who are dead.\"  But soon as he beheld\nI left them not, \"By other way,\" said he,\n\"By other haven shalt thou come to shore,\nNot by this passage; thee a nimbler boat\nMust carry.\"  Then to him thus spake my guide:\n\"Charon!  thyself torment not: so \'t is will\'d,\nWhere will and power are one: ask thou no more.\"\n     Straightway in silence fell the shaggy cheeks\nOf him the boatman o\'er the livid lake,\nAround whose eyes glar\'d wheeling flames.  Meanwhile\nThose spirits, faint and naked, color chang\'d,\nAnd gnash\'d their teeth, soon as the cruel words\nThey heard.  God and their parents they blasphem\'d,\nThe human kind, the place, the time, and seed\nThat did engender them and give them birth.\n     Then all together sorely wailing drew\nTo the curs\'d strand, that every man must pass\nWho fears not God.  Charon, demoniac form,\nWith eyes of burning coal, collects them all,\nBeck\'ning, and each, that lingers, with his oar\nStrikes.  As fall off the light autumnal leaves,\nOne still another following, till the bough\nStrews all its honours on the earth beneath;\nE\'en in like manner Adam\'s evil brood\nCast themselves one by one down from the shore,\nEach at a beck, as falcon at his call.\n     Thus go they over through the umber\'d wave,\nAnd ever they on the opposing bank\nBe landed, on this side another throng\nStill gathers.  \"Son,\" thus spake the courteous guide,\n\"Those, who die subject to the wrath of God,\nAll here together come from every clime,\nAnd to o\'erpass the river are not loth:\nFor so heaven\'s justice goads them on, that fear\nIs turn\'d into desire.  Hence ne\'er hath past\nGood spirit.  If of thee Charon complain,\nNow mayst thou know the import of his words.\"\n     This said, the gloomy region trembling shook\nSo terribly, that yet with clammy dews\nFear chills my brow.  The sad earth gave a blast,\nThat, lightening, shot forth a vermilion flame,\nWhich all my senses conquer\'d quite, and I\nDown dropp\'d, as one with sudden slumber seiz\'d.\n\n\n\nCANTO IV\n\nBROKE the deep slumber in my brain a crash\nOf heavy thunder, that I shook myself,\nAs one by main force rous\'d.  Risen upright,\nMy rested eyes I mov\'d around, and search\'d\nWith fixed ken to know what place it was,\nWherein I stood.  For certain on the brink\nI found me of the lamentable vale,\nThe dread abyss, that joins a thund\'rous sound\nOf plaints innumerable.  Dark and d");
    strcat(expected_filecontent, "eep,\nAnd thick with clouds o\'erspread, mine eye in vain\nExplor\'d its bottom, nor could aught discern.\n     \"Now let us to the blind world there beneath\nDescend;\" the bard began all pale of look:\n\"I go the first, and thou shalt follow next.\"\n     Then I his alter\'d hue perceiving, thus:\n\"How may I speed, if thou yieldest to dread,\nWho still art wont to comfort me in doubt?\"\n     He then:  \"The anguish of that race below\nWith pity stains my che");

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "WEEK");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 12731; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 23: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST23(void)
{
    // informacje o teście
    test_start(23, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6349] = "";

                strcat(expected_filecontent, " that gate\nWe enter\'d first, whose threshold is to none\nDenied, nought else so worthy of regard,\nAs is this river, has thine eye discern\'d,\nO\'er which the flaming volley all is quench\'d.\"\n     So spake my guide; and I him thence besought,\nThat having giv\'n me appetite to know,\nThe food he too would give, that hunger crav\'d.\n     \"In midst of ocean,\" forthwith he began,\n\"A desolate country lies, which Crete is nam\'d,\nUnder whose monarch in old times the world\nLiv\'d pure and chaste.  A mountain rises there,\nCall\'d Ida, joyous once with leaves and streams,\nDeserted now like a forbidden thing.\nIt was the spot which Rhea, Saturn\'s spouse,\nChose for the secret cradle of her son;\nAnd better to conceal him, drown\'d in shouts\nHis infant cries.  Within the mount, upright\nAn ancient form there stands and huge, that turns\nHis shoulders towards Damiata, and at Rome\nAs in his mirror looks.  Of finest gold\nHis head is shap\'d, pure silver are the breast\nAnd arms; thence to the middle is of brass.\nAnd downward all beneath well-temper\'d steel,\nSave the right foot of potter\'s clay, on which\nThan on the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to the lowest depth of all,\nForm there Cocytus, of whose lake (thyself\nShall see it) I here give thee no account.\"\n     Then I to him:  \"If from our world this sluice\nBe thus deriv\'d; wherefore to us but now\nAppears it at this edge?\"  He straight replied:\n\"The place, thou know\'st, is round; and though great part\nThou have already pass\'d, still to the left\nDescending to the nethermost, not yet\nHast thou the circuit made of the whole orb.\nWherefore if aught of new to us appear,\nIt needs not bring up wonder in thy looks.\"\n     Then I again inquir\'d:  \"Where flow the streams\nOf Phlegethon and Lethe? for of one\nThou tell\'st not, and the other of that shower,\nThou say\'st, is form\'d.\"  He answer thus return\'d:\n\"Doubtless thy questions all well pleas\'d I hear.\nYet the red seething wave might have resolv\'d\nOne thou proposest.  Lethe thou shalt see,\nBut not within this hollow, in the place,\nWhither to lave themselves the spirits go,\nWhose blame hath been by penitence remov\'d.\"\nHe added:  \"Time is now we quit the wood.\nLook thou my steps pursue:  the margins give\nSafe passage, unimpeded by the flames;\nFor over them all vapour is extinct.\"\n\n\n\nCANTO XV\n\nOne of the solid margins bears us now\nEnvelop\'d in the mist, that from the stream\nArising, hovers o\'er, and saves from fire\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the mounds,\nSo fram\'d, though not in height or bulk to these\nMade equal, by the master, whosoe\'er\nHe was, that rais\'d them here.  We from the wood\nWere not so far remov\'d, that turning round\nI might not have discern\'d it, when we met\nA troop of spirits, who came beside the pier.\n     They each one ey\'d us, as at eventide\nOne eyes another under a new moon,\nAnd toward us sharpen\'d their sight as keen,\nAs an old tailor at his needle\'s eye.\n     Thus narrowly explor\'d by all the tribe,\nI was agniz\'d of one, who by the skirt\nCaught me, and cried, \"What wonder have we here!\"\n     And I, when he to me outstretch\'d his arm,\nIntently fix\'d my ken on his parch\'d looks,\nThat although smirch\'d with fire, they hinder\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent");
    strcat(expected_filecontent, ";\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefore on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path descend to tread\nOn equal ground with him, but held my head\nBent down, as one who walks in reverent guise.\n     \"What chance or destiny,\" thus be began,\n\"Ere the last day conducts thee here below?\nAnd who is this, that shows to thee the way?\"\n     \"There up aloft,\" I answer\'d, \"in the life\nSerene, I wander\'d in a valley lost,\nBefore mine age had to its fullness reach\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d, and now strikes full upon my heart\nThe dear, benign, paternal image, such\nAs thine was, when so lately thou didst teach me\nThe way for man to win eternity;\nAnd how I priz\'d t");

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "FIT.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6348; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 24: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST24(void)
{
    // informacje o teście
    test_start(24, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6364] = "";

                strcat(expected_filecontent, "emons on our way we went;\nAh fearful company!  but in the church\nWith saints, with gluttons at the tavern\'s mess.\n     Still earnest on the pitch I gaz\'d, to mark\nAll things whate\'er the chasm contain\'d, and those\nWho burn\'d within.  As dolphins, that, in sign\nTo mariners, heave high their arched backs,\nThat thence forewarn\'d they may advise to save\nTheir threaten\'d vessels; so, at intervals,\nTo ease the pain his back some sinner show\'d,\nThen hid more nimbly than the lightning glance.\n     E\'en as the frogs, that of a wat\'ry moat\nStand at the brink, with the jaws only out,\nTheir feet and of the trunk all else concealed,\nThus on each part the sinners stood, but soon\nAs Barbariccia was at hand, so they\nDrew back under the wave.  I saw, and yet\nMy heart doth stagger, one, that waited thus,\nAs it befalls that oft one frog remains,\nWhile the next springs away:  and Graffiacan,\nWho of the fiends was nearest, grappling seiz\'d\nHis clotted locks, and dragg\'d him sprawling up,\nThat he appear\'d to me an otter.  Each\nAlready by their names I knew, so well\nWhen they were chosen, I observ\'d, and mark\'d\nHow one the other call\'d. \"O Rubicant!\nSee that his hide thou with thy talons flay,\"\nShouted together all the cursed crew.\n     Then I:  \"Inform thee, master!  if thou may,\nWhat wretched soul is this, on whom their hand\nHis foes have laid.\"  My leader to his side\nApproach\'d, and whence he came inquir\'d, to whom\nWas answer\'d thus:  \"Born in Navarre\'s domain\nMy mother plac\'d me in a lord\'s retinue,\nFor she had borne me to a losel vile,\nA spendthrift of his substance and himself.\nThe good king Thibault after that I serv\'d,\nTo peculating here my thoughts were turn\'d,\nWhereof I give account in this dire heat.\"\n     Straight Ciriatto, from whose mouth a tusk\nIssued on either side, as from a boar,\nRipt him with one of these.  \'Twixt evil claws\nThe mouse had fall\'n:  but Barbariccia cried,\nSeizing him with both arms:  \"Stand thou apart,\nWhile I do fix him on my prong transpierc\'d.\"\nThen added, turning to my guide his face,\n\"Inquire of him, if more thou wish to learn,\nEre he again be rent.\"  My leader thus:\n\"Then tell us of the partners in thy guilt;\nKnowest thou any sprung of Latian land\nUnder the tar?\"--\"I parted,\" he replied,\n\"But now from one, who sojourn\'d not far thence;\nSo were I under shelter now with him!\nNor hook nor talon then should scare me more.\"--.\n     \"Too long we suffer,\" Libicocco cried,\nThen, darting forth a prong, seiz\'d on his arm,\nAnd mangled bore away the sinewy part.\nHim Draghinazzo by his thighs beneath\nWould next have caught, whence angrily their chief,\nTurning on all sides round, with threat\'ning brow\nRestrain\'d them.  When their strife a little ceas\'d,\nOf him, who yet was gazing on his wound,\nMy teacher thus without delay inquir\'d:\n\"Who was the spirit, from whom by evil hap\nParting, as thou has told, thou cam\'st to shore?\"--\n     \"It was the friar Gomita,\" he rejoin\'d,\n\"He of Gallura, vessel of all guile,\nWho had his master\'s enemies in hand,\nAnd us\'d them so that they commend him well.\nMoney he took, and them at large dismiss\'d.\nSo he reports:  and in each other charge\nCommitted to his keeping, play\'d the part\nOf barterer to the height:   with him doth herd\nThe chief of Logodoro, Michel Zanche.\nSardinia is a theme, whereof their tongue\nIs never weary.  Out! alas! behold\nThat other, how he grins!  More would I say,\nBut tremble lest he mean to maul me sore.\"\n     Their captain then to Farfarello turning,\nWho roll\'d his moony eyes in act to strike,\nRebuk\'d him thus:  \"Off! cursed bird! Avaunt!\"--\n     \"If ye desire to see or hear,\" he thus\nQuaking with dread resum\'d, \"or Tuscan spirits\nOr Lombard, I will cause them to appear.\nMeantime let these ill talons bate their fury,\nSo that no vengeance they may fear from them,\nAnd I, remaining in this self-same place,\nWill for myself but one, make sev\'n appear,\nWhen my shrill whistle shall be heard; for so\nOur custom is to call each other up.\"\n     Cagnazzo at that word deriding grinn\'d,\nThen wagg\'d the head and spake:  \"Hear his device,\nMischievous as he is, to plunge him down");
    strcat(expected_filecontent, ".\"\n     Whereto he thus, who fail\'d not in rich store\nOf nice-wove toils; \" Mischief forsooth extreme,\nMeant only to procure myself more woe!\"\n     No longer Alichino then refrain\'d,\nBut thus, the rest gainsaying, him bespake:\n\"If thou do cast thee down, I not on foot\nWill chase thee, but above the pitch will beat\nMy plumes.  Quit we the vantage ground, and let\nThe bank be as a shield, that we may see\nIf singly thou prevail against us all.\"\n     Now, reader, of new sport expect to hear!\n     They each one turn\'d his eyes to the\' other shore,\nHe first, who was the hardest to persuade.\nThe spirit of Navarre chose well his time,\nPlanted his feet on land, and at one leap\nEscaping disappointed their resolve.\n     Them quick resentment stung, but him the most,\nWho was the cause of failure; in pursuit\nHe therefore sped, exclaiming;  \"Thou art caught.\"\n     But little it avail\'d:  terror outstripp\'d\nHis following flight:  the other plung\'d beneath,\nAnd he with upward pinion rais\'d his breast:\nE\'en thus the water-fowl, when she perceives\nThe falcon near, dives instant down, while he\nEnrag\'d and spent retires.  That mockery\nIn Calcabrina fury stirr\'d, who flew\nAfter him, with desire of strife inflam\'d;\nAnd, for the barterer had \'scap\'d, so turn\'d\nHis talons on his comrade. O\'er the dyke\nIn grapple close they join\'d; but the\' other prov\'d\nA goshawk able to rend well his foe;\nAnd in the boiling lake both fell.  The heat\nWas umpire soon between them, but in vain\nTo lift themselves they strove, so fast were glued\nTheir pennons.  Barbariccia, as the rest,\nThat chance lamenting, four in flight dispatch\'d\nFrom the\' other coast, with all their weapons arm\'d.\nThey, to their post on each side speedily\nDescending, stretch\'d their hooks toward the fiends,\nWho flounder\'d, inly burning from their scars:\nAnd we departing left them to that broil.\n\n\n\nCANTO XXIII\n\nIN silence and in solitude we went,\nOne first, the other following his steps,\nAs minor friars journeying on their road.\n     The present fray had turn\'d my thoughts to muse\nUpon old Aesop\'s fable, where he told\nWhat fate unto the mouse and frog befell.\nFor language hath not sounds more like in sense,\nThan are these chances, if the origin\nAnd end of each be heedfully compar\'d.\nAnd as one thought b");

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "ORDER.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6363; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 25: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST25(void)
{
    // informacje o teście
    test_start(25, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[1462] = "";

                strcat(expected_filecontent, "mpts them,\nThey wait not for the motions of the will\nIn natures most sincere.  I did but smile,\nAs one who winks; and thereupon the shade\nBroke off, and peer\'d into mine eyes, where best\nOur looks interpret. \"So to good event\nMayst thou conduct such great emprize,\" he cried,\n\"Say, why across thy visage beam\'d, but now,\nThe lightning of a smile!\"  On either part\nNow am I straiten\'d; one conjures me speak,\nTh\' other to silence binds me: whence a sigh\nI utter, and the sigh is heard.  \"Speak on; \"\nThe teacher cried;  \"and do not fear to speak,\nBut tell him what so earnestly he asks.\"\nWhereon I thus:  \"Perchance, O ancient spirit!\nThou marvel\'st at my smiling. There is room\nFor yet more wonder.  He who guides my ken\nOn high, he is that Mantuan, led by whom\nThou didst presume of men arid gods to sing.\nIf other cause thou deem\'dst for which I smil\'d,\nLeave it as not the true one; and believe\nThose words, thou spak\'st of him, indeed the cause.\"\n     Now down he bent t\' embrace my teacher\'s feet;\nBut he forbade him:  \"Brother!  do it not:\nThou art a shadow, and behold\'st a shade.\"\nHe rising answer\'d thus:  \"Now hast thou prov\'d\nThe force and ardour of the love I bear thee,\nWhen I forget we are but things of air,\nAnd as a substance treat an empty shade.\"\n\n\n\nCANTO XXII\n\nNow we had left the angel, who had turn\'d\nTo the sixth circle our ascending step,\nOne gash from off my forehead raz\'d: while they,\nWhose wishes tend to justice, shouted forth:\n\"Bles");

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "CASE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 1461; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 26: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST26(void)
{
    // informacje o teście
    test_start(26, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[915] = "";

                strcat(expected_filecontent, "e had tended still\nThe thread and cordwain; and too late repents.\n     \"See next the wretches, who the needle left,\nThe shuttle and the spindle, and became\nDiviners:  baneful witcheries they wrought\nWith images and herbs.  But onward now:\nFor now doth Cain with fork of thorns confine\nOn either hemisphere, touching the wave\nBeneath the towers of Seville.  Yesternight\nThe moon was round.  Thou mayst remember well:\nFor she good service did thee in the gloom\nOf the deep wood.\"  This said, both onward mov\'d.\n\n\n\nCANTO XXI\n\nTHUS we from bridge to bridge, with other talk,\nThe which my drama cares not to rehearse,\nPass\'d on; and to the summit reaching, stood\nTo view another gap, within the round\nOf Malebolge, other bootless pangs.\n     Marvelous darkness shadow\'d o\'er the place.\n     In the Venetians\' arsenal as boils\nThrough wintry months tenacious pitch, to smear\nTheir unsound vessels; for th\' inclement time");

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "FINALFIG.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 914; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 27: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST27(void)
{
    // informacje o teście
    test_start(27, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(6363, 1);
            char expected_filecontent[6364] = "";

            strcat(expected_filecontent, "emons on our way we went;\nAh fearful company!  but in the church\nWith saints, with gluttons at the tavern\'s mess.\n     Still earnest on the pitch I gaz\'d, to mark\nAll things whate\'er the chasm contain\'d, and those\nWho burn\'d within.  As dolphins, that, in sign\nTo mariners, heave high their arched backs,\nThat thence forewarn\'d they may advise to save\nTheir threaten\'d vessels; so, at intervals,\nTo ease the pain his back some sinner show\'d,\nThen hid more nimbly than the lightning glance.\n     E\'en as the frogs, that of a wat\'ry moat\nStand at the brink, with the jaws only out,\nTheir feet and of the trunk all else concealed,\nThus on each part the sinners stood, but soon\nAs Barbariccia was at hand, so they\nDrew back under the wave.  I saw, and yet\nMy heart doth stagger, one, that waited thus,\nAs it befalls that oft one frog remains,\nWhile the next springs away:  and Graffiacan,\nWho of the fiends was nearest, grappling seiz\'d\nHis clotted locks, and dragg\'d him sprawling up,\nThat he appear\'d to me an otter.  Each\nAlready by their names I knew, so well\nWhen they were chosen, I observ\'d, and mark\'d\nHow one the other call\'d. \"O Rubicant!\nSee that his hide thou with thy talons flay,\"\nShouted together all the cursed crew.\n     Then I:  \"Inform thee, master!  if thou may,\nWhat wretched soul is this, on whom their hand\nHis foes have laid.\"  My leader to his side\nApproach\'d, and whence he came inquir\'d, to whom\nWas answer\'d thus:  \"Born in Navarre\'s domain\nMy mother plac\'d me in a lord\'s retinue,\nFor she had borne me to a losel vile,\nA spendthrift of his substance and himself.\nThe good king Thibault after that I serv\'d,\nTo peculating here my thoughts were turn\'d,\nWhereof I give account in this dire heat.\"\n     Straight Ciriatto, from whose mouth a tusk\nIssued on either side, as from a boar,\nRipt him with one of these.  \'Twixt evil claws\nThe mouse had fall\'n:  but Barbariccia cried,\nSeizing him with both arms:  \"Stand thou apart,\nWhile I do fix him on my prong transpierc\'d.\"\nThen added, turning to my guide his face,\n\"Inquire of him, if more thou wish to learn,\nEre he again be rent.\"  My leader thus:\n\"Then tell us of the partners in thy guilt;\nKnowest thou any sprung of Latian land\nUnder the tar?\"--\"I parted,\" he replied,\n\"But now from one, who sojourn\'d not far thence;\nSo were I under shelter now with him!\nNor hook nor talon then should scare me more.\"--.\n     \"Too long we suffer,\" Libicocco cried,\nThen, darting forth a prong, seiz\'d on his arm,\nAnd mangled bore away the sinewy part.\nHim Draghinazzo by his thighs beneath\nWould next have caught, whence angrily their chief,\nTurning on all sides round, with threat\'ning brow\nRestrain\'d them.  When their strife a little ceas\'d,\nOf him, who yet was gazing on his wound,\nMy teacher thus without delay inquir\'d:\n\"Who was the spirit, from whom by evil hap\nParting, as thou has told, thou cam\'st to shore?\"--\n     \"It was the friar Gomita,\" he rejoin\'d,\n\"He of Gallura, vessel of all guile,\nWho had his master\'s enemies in hand,\nAnd us\'d them so that they commend him well.\nMoney he took, and them at large dismiss\'d.\nSo he reports:  and in each other charge\nCommitted to his keeping, play\'d the part\nOf barterer to the height:   with him doth herd\nThe chief of Logodoro, Michel Zanche.\nSardinia is a theme, whereof their tongue\nIs never weary.  Out! alas! behold\nThat other, how he grins!  More would I say,\nBut tremble lest he mean to maul me sore.\"\n     Their captain then to Farfarello turning,\nWho roll\'d his moony eyes in act to strike,\nRebuk\'d him thus:  \"Off! cursed bird! Avaunt!\"--\n     \"If ye desire to see or hear,\" he thus\nQuaking with dread resum\'d, \"or Tuscan spirits\nOr Lombard, I will cause them to appear.\nMeantime let these ill talons bate their fury,\nSo that no vengeance they may fear from them,\nAnd I, remaining in this self-same place,\nWill for myself but one, make sev\'n appear,\nWhen my shrill whistle shall be heard; for so\nOur custom is to call each other up.\"\n     Cagnazzo at that word deriding grinn\'d,\nThen wagg\'d the head and spake:  \"Hear his device,\nMischievous as he is, to plunge him down");
    strcat(expected_filecontent, ".\"\n     Whereto he thus, who fail\'d not in rich store\nOf nice-wove toils; \" Mischief forsooth extreme,\nMeant only to procure myself more woe!\"\n     No longer Alichino then refrain\'d,\nBut thus, the rest gainsaying, him bespake:\n\"If thou do cast thee down, I not on foot\nWill chase thee, but above the pitch will beat\nMy plumes.  Quit we the vantage ground, and let\nThe bank be as a shield, that we may see\nIf singly thou prevail against us all.\"\n     Now, reader, of new sport expect to hear!\n     They each one turn\'d his eyes to the\' other shore,\nHe first, who was the hardest to persuade.\nThe spirit of Navarre chose well his time,\nPlanted his feet on land, and at one leap\nEscaping disappointed their resolve.\n     Them quick resentment stung, but him the most,\nWho was the cause of failure; in pursuit\nHe therefore sped, exclaiming;  \"Thou art caught.\"\n     But little it avail\'d:  terror outstripp\'d\nHis following flight:  the other plung\'d beneath,\nAnd he with upward pinion rais\'d his breast:\nE\'en thus the water-fowl, when she perceives\nThe falcon near, dives instant down, while he\nEnrag\'d and spent retires.  That mockery\nIn Calcabrina fury stirr\'d, who flew\nAfter him, with desire of strife inflam\'d;\nAnd, for the barterer had \'scap\'d, so turn\'d\nHis talons on his comrade. O\'er the dyke\nIn grapple close they join\'d; but the\' other prov\'d\nA goshawk able to rend well his foe;\nAnd in the boiling lake both fell.  The heat\nWas umpire soon between them, but in vain\nTo lift themselves they strove, so fast were glued\nTheir pennons.  Barbariccia, as the rest,\nThat chance lamenting, four in flight dispatch\'d\nFrom the\' other coast, with all their weapons arm\'d.\nThey, to their post on each side speedily\nDescending, stretch\'d their hooks toward the fiends,\nWho flounder\'d, inly burning from their scars:\nAnd we departing left them to that broil.\n\n\n\nCANTO XXIII\n\nIN silence and in solitude we went,\nOne first, the other following his steps,\nAs minor friars journeying on their road.\n     The present fray had turn\'d my thoughts to muse\nUpon old Aesop\'s fable, where he told\nWhat fate unto the mouse and frog befell.\nFor language hath not sounds more like in sense,\nThan are these chances, if the origin\nAnd end of each be heedfully compar\'d.\nAnd as one thought b");

            struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "ORDER.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int i;
            for (i = 0; i < 353; ++i)
            {
                int res = file_read(filecontent + 18 * i, 18, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            }

            int res = file_read(filecontent + 18 * i, 18, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6363);

            // jeśli jest, to raportuj błąd
            test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

            onerror_compare_memory(expected_filecontent, filecontent, 6363);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 28: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST28(void)
{
    // informacje o teście
    test_start(28, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char *filecontent0 = (char *)calloc(10240, 1);
    char *filecontent1 = (char *)calloc(13248, 1);
    char *filecontent2 = (char *)calloc(12731, 1);
    char *filecontent3 = (char *)calloc(6348, 1);
    char *filecontent4 = (char *)calloc(6363, 1);
    char *filecontent5 = (char *)calloc(1461, 1);
    char *filecontent6 = (char *)calloc(914, 1);

            char expected_filecontent0[10241] = "";
    char expected_filecontent1[13249] = "";
    char expected_filecontent2[12732] = "";
    char expected_filecontent3[6349] = "";
    char expected_filecontent4[6364] = "";
    char expected_filecontent5[1462] = "";
    char expected_filecontent6[915] = "";

            strcat(expected_filecontent0, "s Beatrice?\"--\"See her,\" she replied,\n\"Beneath the fresh leaf seated on its root.\nBehold th\' associate choir that circles her.\nThe others, with a melody more sweet\nAnd more profound, journeying to higher realms,\nUpon the Gryphon tend.\"  If there her words\nWere clos\'d, I know not; but mine eyes had now\nTa\'en view of her, by whom all other thoughts\nWere barr\'d admittance.  On the very ground\nAlone she sat, as she had there been left\nA guard upon the wain, which I beheld\nBound to the twyform beast.  The seven nymphs\nDid make themselves a cloister round about her,\nAnd in their hands upheld those lights secure\nFrom blast septentrion and the gusty south.\n     \"A little while thou shalt be forester here:\nAnd citizen shalt be forever with me,\nOf that true Rome, wherein Christ dwells a Roman\nTo profit the misguided world, keep now\nThine eyes upon the car; and what thou seest,\nTake heed thou write, returning to that place.\"\n     Thus Beatrice: at whose feet inclin\'d\nDevout, at her behest, my thought and eyes,\nI, as she bade, directed.  Never fire,\nWith so swift motion, forth a stormy cloud\nLeap\'d downward from the welkin\'s farthest bound,\nAs I beheld the bird of Jove descending\nPounce on the tree, and, as he rush\'d, the rind,\nDisparting crush beneath him, buds much more\nAnd leaflets.  On the car with all his might\nHe struck, whence, staggering like a ship, it reel\'d,\nAt random driv\'n, to starboard now, o\'ercome,\nAnd now to larboard, by the vaulting waves.\n     Next springing up into the chariot\'s womb\nA fox I saw, with hunger seeming pin\'d\nOf all good food.  But, for his ugly sins\nThe saintly maid rebuking him, away\nScamp\'ring he turn\'d, fast as his hide-bound corpse\nWould bear him.  Next, from whence before he came,\nI saw the eagle dart into the hull\nO\' th\' car, and leave it with his feathers lin\'d;\nAnd then a voice, like that which issues forth\nFrom heart with sorrow riv\'d, did issue forth\nFrom heav\'n, and, \"O poor bark of mine!\" it cried,\n\"How badly art thou freighted!\"  Then, it seem\'d,\nThat the earth open\'d between either wheel,\nAnd I beheld a dragon issue thence,\nThat through the chariot fix\'d his forked train;\nAnd like a wasp that draggeth back the sting,\nSo drawing forth his baleful train, he dragg\'d\nPart of the bottom forth, and went his way\nExulting.  What remain\'d, as lively turf\nWith green herb, so did clothe itself with plumes,\nWhich haply had with purpose chaste and kind\nBeen offer\'d; and therewith were cloth\'d the wheels,\nBoth one and other, and the beam, so quickly\nA sigh were not breath\'d sooner.  Thus transform\'d,\nThe holy structure, through its several parts,\nDid put forth heads, three on the beam, and one\nOn every side; the first like oxen horn\'d,\nBut with a single horn upon their front\nThe four.  Like monster sight hath never seen.\nO\'er it methought there sat, secure as rock\nOn mountain\'s lofty top, a shameless whore,\nWhose ken rov\'d loosely round her.  At her side,\nAs \'t were that none might bear her off, I saw\nA giant stand; and ever, and anon\nThey mingled kisses.  But, her lustful eyes\nChancing on me to wander, that fell minion\nScourg\'d her from head to foot all o\'er; then full\nOf jealousy, and fierce with rage, unloos\'d\nThe monster, and dragg\'d on, so far across\nThe forest, that from me its shades alone\nShielded the harlot and the new-form\'d brute.\n\n\n\nCANTO XXXIII\n\n\"The heathen, Lord!  are come!\" responsive thus,\nThe trinal now, and now the virgin band\nQuaternion, their sweet psalmody began,\nWeeping; and Beatrice listen\'d, sad\nAnd sighing, to the song\', in such a mood,\nThat Mary, as she stood beside the cross,\nWas scarce more chang\'d.  But when they gave her place\nTo speak, then, risen upright on her feet,\nShe, with a colour glowing bright as fire,\nDid answer: \"Yet a little while, and ye\nShall see me not; and, my beloved sisters,\nAgain a little while, and ye shall see me.\"\n     Before her then she marshall\'d all the seven,\nAnd, beck\'ning only motion\'d me, the dame,\nAnd that remaining sage, to follow her.\n     So on she pass\'d; and had not set, I ween,\nHer tenth step to the ground, when with mine eyes\nHer ");
    strcat(expected_filecontent0, "eyes encounter\'d; and, with visage mild,\n\"So mend thy pace,\" she cried, \"that if my words\nAddress thee, thou mayst still be aptly plac\'d\nTo hear them.\"  Soon as duly to her side\nI now had hasten\'d:  \"Brother!\" she began,\n\"Why mak\'st thou no attempt at questioning,\nAs thus we walk together?\"  Like to those\nWho, speaking with too reverent an awe\nBefore their betters, draw not forth the voice\nAlive unto their lips, befell me shell\nThat I in sounds imperfect thus began:\n\"Lady!  what I have need of, that thou know\'st,\nAnd what will suit my need.\"  She answering thus:\n\"Of fearfulness and shame, I will, that thou\nHenceforth do rid thee: that thou speak no more,\nAs one who dreams.  Thus far be taught of me:\nThe vessel, which thou saw\'st the serpent break,\nWas and is not: let him, who hath the blame,\nHope not to scare God\'s vengeance with a sop.\nWithout an heir for ever shall not be\nThat eagle, he, who left the chariot plum\'d,\nWhich monster made it first and next a prey.\nPlainly I view, and therefore speak, the stars\nE\'en now approaching, whose conjunction, free\nFrom all impediment and bar, brings on\nA season, in the which, one sent from God,\n(Five hundred, five, and ten, do mark him out)\nThat foul one, and th\' accomplice of her guilt,\nThe giant, both shall slay.  And if perchance\nMy saying, dark as Themis or as Sphinx,\nFail to persuade thee, (since like them it foils\nThe intellect with blindness) yet ere long\nEvents shall be the Naiads, that will solve\nThis knotty riddle, and no damage light\nOn flock or field.  Take heed; and as these words\nBy me are utter\'d, teach them even so\nTo those who live that life, which is a race\nTo death: and when thou writ\'st them, keep in mind\nNot to conceal how thou hast seen the plant,\nThat twice hath now been spoil\'d.  This whoso robs,\nThis whoso plucks, with blasphemy of deed\nSins against God, who for his use alone\nCreating hallow\'d it.  For taste of this,\nIn pain and in desire, five thousand years\nAnd upward, the first soul did yearn for him,\nWho punish\'d in himself the fatal gust.\n     \"Thy reason slumbers, if it deem this height\nAnd summit thus inverted of the plant,\nWithout due cause: and were not vainer thoughts,\nAs Elsa\'s numbing waters, to thy soul,\nAnd their fond pleasures had not dyed it dark\nAs Pyramus the mulberry, thou hadst seen,\nIn such momentous circumstance alone,\nGod\'s equal justice morally implied\nIn the forbidden tree.  But since I mark thee\nIn understanding harden\'d into stone,\nAnd, to that hardness, spotted too and stain\'d,\nSo that thine eye is dazzled at my word,\nI will, that, if not written, yet at least\nPainted thou take it in thee, for the cause,\nThat one brings home his staff inwreath\'d with palm.\n     \"I thus:  \"As wax by seal, that changeth not\nIts impress, now is stamp\'d my brain by thee.\nBut wherefore soars thy wish\'d-for speech so high\nBeyond my sight, that loses it the more,\nThe more it strains to reach it?\" --\"To the end\nThat thou mayst know,\" she answer\'d straight, \"the school,\nThat thou hast follow\'d; and how far behind,\nWhen following my discourse, its learning halts:\nAnd mayst behold your art, from the divine\nAs distant, as the disagreement is\n\'Twixt earth and heaven\'s most high and rapturous orb.\"\n     \"I not remember,\" I replied, \"that e\'er\nI was estrang\'d from thee, nor for such fault\nDoth conscience chide me.\"  Smiling she return\'d:\n\"If thou canst, not remember, call to mind\nHow lately thou hast drunk of Lethe\'s wave;\nAnd, sure as smoke doth indicate a flame,\nIn that forgetfulness itself conclude\nBlame from thy alienated will incurr\'d.\nFrom henceforth verily my words shall be\nAs naked as will suit them to appear\nIn thy unpractis\'d view.\"  More sparkling now,\nAnd with retarded course the sun possess\'d\nThe circle of mid-day, that varies still\nAs th\' aspect varies of each several clime,\nWhen, as one, sent in vaward of a troop\nFor escort, pauses, if perchance he spy\nVestige of somewhat strange and rare: so paus\'d\nThe sev\'nfold band, arriving at the verge\nOf a dun umbrage hoar, such as is seen,\nBeneath green leaves and gloomy branches, oft\nTo overbrow a bleak ");
    strcat(expected_filecontent0, "and alpine cliff.\nAnd, where they stood, before them, as it seem\'d,\nTigris and Euphrates both beheld,\nForth from one fountain issue; and, like friends,\nLinger at parting. \"O enlight\'ning beam!\nO glory of our kind!  beseech thee say\nWhat water this, which from one source deriv\'d\nItself removes to distance from itself?\"\n     To such entreaty answer thus was made:\n\"Entreat Matilda, that she teach thee this.\"\n     And here, as one, who clears himself of blame\nImputed, the fair dame return\'d:  \"Of me\nHe this and more hath learnt; and I am safe\nThat Lethe\'s water hath not hid it from him.\"\n     And Beatrice:  \"Some more pressing care\nThat oft the memory \'reeves, perchance hath made\nHis mind\'s eye dark.  But lo!  where Eunoe cows!\nLead thither; and, as thou art wont, revive\nHis fainting virtue.\"  As a courteous spirit,\nThat proffers no excuses, but as soon\nAs he hath token of another\'s will,\nMakes it his own; when she had ta\'en me, thus\nThe lovely maiden mov\'d her on, and call\'d\nTo Statius with an air most lady-like:\n\"Come thou with him.\"  Were further space allow\'d,\nThen, Reader, might I sing, though but in part,\nThat beverage, with whose sweetness I had ne\'er\nBeen sated.  But, since all the leaves are full,\nAppointed for this second strain, mine art\nWith warning bridle checks me.  I return\'d\nFrom the most holy wave, regenerate,\nIf \'en as new plants renew\'d with foliage new,\nPure and made apt for mounting to the stars.\n\n\n\nNOTES TO PURGATORY\n\nCANTO I\n\nVerse 1.  O\'er better waves.]  Berni, Orl. Inn. L 2. c. i.\nPer correr maggior acqua alza le vele,\nO debil navicella del mio ingegno.\n\nv. 11.  Birds of chattering note.]  For the fable of the\ndaughters of Pierus, who challenged the muses to sing, and were\nby them\nchanged into magpies, see Ovid, Met. 1. v. fab. 5.\n\nv. 19.  Planet.]  Venus.\n\nv. 20.  Made all the orient laugh.]  Hence Chaucer, Knight\'s\nTale: And all the orisont laugheth of the sight.\n\nIt is sometimes read \"orient.\"\n\nv. 24.  Four stars.]  Symbolical of the four cardinal virtues,\nPrudence Justice, Fortitude, and T");strcat(expected_filecontent1, ", if chance a passing cloud\nSo sail across, that opposite it hangs,\nSuch then Antaeus seem\'d, as at mine ease\nI mark\'d him stooping.  I were fain at times\nT\' have pass\'d another way.  Yet in th\' abyss,\nThat Lucifer with Judas low ingulfs,\nI,ightly he plac\'d us; nor there leaning stay\'d,\nBut rose as in a bark the stately mast.\n\n\n\nCANTO XXXII\n\nCOULD I command rough rhimes and hoarse, to suit\nThat hole of sorrow, o\'er which ev\'ry rock\nHis firm abutment rears, then might the vein\nOf fancy rise full springing:  but not mine\nSuch measures, and with falt\'ring awe I touch\nThe mighty theme; for to describe the depth\nOf all the universe, is no emprize\nTo jest with, and demands a tongue not us\'d\nTo infant babbling.  But let them assist\nMy song, the tuneful maidens, by whose aid\nAmphion wall\'d in Thebes, so with the truth\nMy speech shall best accord.  Oh ill-starr\'d folk,\nBeyond all others wretched!  who abide\nIn such a mansion, as scarce thought finds words\nTo speak of, better had ye here on earth\nBeen flocks or mountain goats.  As down we stood\nIn the dark pit beneath the giants\' feet,\nBut lower far than they, and I did gaze\nStill on the lofty battlement, a voice\nBespoke me thus:  \"Look how thou walkest.  Take\nGood heed, thy soles do tread not on the heads\nOf thy poor brethren.\"  Thereupon I turn\'d,\nAnd saw before and underneath my feet\nA lake, whose frozen surface liker seem\'d\nTo glass than water.  Not so thick a veil\nIn winter e\'er hath Austrian Danube spread\nO\'er his still course, nor Tanais far remote\nUnder the chilling sky.  Roll\'d o\'er that mass\nHad Tabernich or Pietrapana fall\'n,\nNot e\'en its rim had creak\'d. As peeps the frog\nCroaking above the wave, what time in dreams\nThe village gleaner oft pursues her toil,\nSo, to where modest shame appears, thus low\nBlue pinch\'d and shrin\'d in ice the spirits stood,\nMoving their teeth in shrill note like the stork.\nHis face each downward held; their mouth the cold,\nTheir eyes express\'d the dolour of their heart.\n     A space I look\'d around, then at my feet\nSaw two so strictly join\'d, that of their head\nThe very hairs were mingled.  \"Tell me ye,\nWhose bosoms thus together press,\" said I,\n\"Who are ye?\"  At that sound their necks they bent,\nAnd when their looks were lifted up to me,\nStraightway their eyes, before all moist within,\nDistill\'d upon their lips, and the frost bound\nThe tears betwixt those orbs and held them there.\nPlank unto plank hath never cramp clos\'d up\nSo stoutly.  Whence like two enraged goats\nThey clash\'d together; them such fury seiz\'d.\n     And one, from whom the cold both ears had reft,\nExclaim\'d, still looking downward: \"Why on us\nDost speculate so long?  If thou wouldst know\nWho are these two, the valley, whence his wave\nBisenzio slopes, did for its master own\nTheir sire Alberto, and next him themselves.\nThey from one body issued; and throughout\nCaina thou mayst search, nor find a shade\nMore worthy in congealment to be fix\'d,\nNot him, whose breast and shadow Arthur\'s land\nAt that one blow dissever\'d, not Focaccia,\nNo not this spirit, whose o\'erjutting head\nObstructs my onward view:  he bore the name\nOf Mascheroni:  Tuscan if thou be,\nWell knowest who he was:  and to cut short\nAll further question, in my form behold\nWhat once was Camiccione.  I await\nCarlino here my kinsman, whose deep guilt\nShall wash out mine.\"  A thousand visages\nThen mark\'d I, which the keen and eager cold\nHad shap\'d into a doggish grin; whence creeps\nA shiv\'ring horror o\'er me, at the thought\nOf those frore shallows.  While we journey\'d on\nToward the middle, at whose point unites\nAll heavy substance, and I trembling went\nThrough that eternal chillness, I know not\nIf will it were or destiny, or chance,\nBut, passing \'midst the heads, my foot did strike\nWith violent blow against the face of one.\n     \"Wherefore dost bruise me?\" weeping, he exclaim\'d,\n\"Unless thy errand be some fresh revenge\nFor Montaperto, wherefore troublest me?\"\n     I thus:  \"Instructor, now await me here,\nThat I through him may rid me of my doubt.\nThenceforth what haste thou wilt.\"  The teacher paus\'d,\nAnd to that shade I s");
    strcat(expected_filecontent1, "pake, who bitterly\nStill curs\'d me in his wrath.  \"What art thou, speak,\nThat railest thus on others?\"  He replied:\n\"Now who art thou, that smiting others\' cheeks\nThrough Antenora roamest, with such force\nAs were past suff\'rance, wert thou living still?\"\n     \"And I am living, to thy joy perchance,\"\nWas my reply, \"if fame be dear to thee,\nThat with the rest I may thy name enrol.\"\n     \"The contrary of what I covet most,\"\nSaid he, \"thou tender\'st:  hence; nor vex me more.\nIll knowest thou to flatter in this vale.\"\n     Then seizing on his hinder scalp, I cried:\n\"Name thee, or not a hair shall tarry here.\"\n     \"Rend all away,\" he answer\'d, \"yet for that\nI will not tell nor show thee who I am,\nThough at my head thou pluck a thousand times.\"\n     Now I had grasp\'d his tresses, and stript off\nMore than one tuft, he barking, with his eyes\nDrawn in and downward, when another cried,\n\"What ails thee, Bocca?  Sound not loud enough\nThy chatt\'ring teeth, but thou must bark outright?\nWhat devil wrings thee?\"--\" Now,\" said I, \"be dumb,\nAccursed traitor!  to thy shame of thee\nTrue tidings will I bear.\"--\" Off,\" he replied,\n\"Tell what thou list; but as thou escape from hence\nTo speak of him whose tongue hath been so glib,\nForget not:  here he wails the Frenchman\'s gold.\n\'Him of Duera,\' thou canst say, \'I mark\'d,\nWhere the starv\'d sinners pine.\'  If thou be ask\'d\nWhat other shade was with them, at thy side\nIs Beccaria, whose red gorge distain\'d\nThe biting axe of Florence.  Farther on,\nIf I misdeem not, Soldanieri bides,\nWith Ganellon, and Tribaldello, him\nWho op\'d Faenza when the people slept.\"\n     We now had left him, passing on our way,\nWhen I beheld two spirits by the ice\nPent in one hollow, that the head of one\nWas cowl unto the other; and as bread\nIs raven\'d up through hunger, th\' uppermost\nDid so apply his fangs to th\' other\'s brain,\nWhere the spine joins it.  Not more furiously\nOn Menalippus\' temples Tydeus gnaw\'d,\nThan on that skull and on its garbage he.\n     \"O thou who show\'st so beastly sign of hate\n\'Gainst him thou prey\'st on, let me hear,\" said I\n\"The cause, on such condition, that if right\nWarrant thy grievance, knowing who ye are,\nAnd what the colour of his sinning was,\nI may repay thee in the world above,\nIf that, wherewith I speak be moist so long.\"\n\n\n\nCANTO XXXIII\n\nHIS jaws uplifting from their fell repast,\nThat sinner wip\'d them on the hairs o\' th\' head,\nWhich he behind had mangled, then began:\n\"Thy will obeying, I call up afresh\nSorrow past cure, which but to think of wrings\nMy heart, or ere I tell on\'t. But if words,\nThat I may utter, shall prove seed to bear\nFruit of eternal infamy to him,\nThe traitor whom I gnaw at, thou at once\nShalt see me speak and weep.  Who thou mayst be\nI know not, nor how here below art come:\nBut Florentine thou seemest of a truth,\nWhen I do hear thee.  Know I was on earth\nCount Ugolino, and th\' Archbishop he\nRuggieri.  Why I neighbour him so close,\nNow list.  That through effect of his ill thoughts\nIn him my trust reposing, I was ta\'en\nAnd after murder\'d, need is not I tell.\nWhat therefore thou canst not have heard, that is,\nHow cruel was the murder, shalt thou hear,\nAnd know if he have wrong\'d me.  A small grate\nWithin that mew, which for my sake the name\nOf famine bears, where others yet must pine,\nAlready through its opening sev\'ral moons\nHad shown me, when I slept the evil sleep,\nThat from the future tore the curtain off.\nThis one, methought, as master of the sport,\nRode forth to chase the gaunt wolf and his whelps\nUnto the mountain, which forbids the sight\nOf Lucca to the Pisan.  With lean brachs\nInquisitive and keen, before him rang\'d\nLanfranchi with Sismondi and Gualandi.\nAfter short course the father and the sons\nSeem\'d tir\'d and lagging, and methought I saw\nThe sharp tusks gore their sides.  When I awoke\nBefore the dawn, amid their sleep I heard\nMy sons (for they were with me) weep and ask\nFor bread.  Right cruel art thou, if no pang\nThou feel at thinking what my heart foretold;\nAnd if not now, why use thy tears to flow?\nNow had they waken\'d; and the hour drew near\nWhen they we");
    strcat(expected_filecontent1, "re wont to bring us food; the mind\nOf each misgave him through his dream, and I\nHeard, at its outlet underneath lock\'d up\nThe\' horrible tower:  whence uttering not a word\nI look\'d upon the visage of my sons.\nI wept not:  so all stone I felt within.\nThey wept:  and one, my little Anslem, cried:\n\"Thou lookest so!  Father what ails thee?\"  Yet\nI shed no tear, nor answer\'d all that day\nNor the next night, until another sun\nCame out upon the world.  When a faint beam\nHad to our doleful prison made its way,\nAnd in four countenances I descry\'d\nThe image of my own, on either hand\nThrough agony I bit, and they who thought\nI did it through desire of feeding, rose\nO\' th\' sudden, and cried, \'Father, we should grieve\nFar less, if thou wouldst eat of us: thou gav\'st\nThese weeds of miserable flesh we wear,\nAnd do thou strip them off from us again.\'\nThen, not to make them sadder, I kept down\nMy spirit in stillness.  That day and the next\nWe all were silent.  Ah, obdurate earth!\nWhy open\'dst not upon us?  When we came\nTo the fourth day, then Geddo at my feet\nOutstretch\'d did fling him, crying, \'Hast no help\nFor me, my father!\'  \"There he died, and e\'en\nPlainly as thou seest me, saw I the three\nFall one by one \'twixt the fifth day and sixth:\nWhence I betook me now grown blind to grope\nOver them all, and for three days aloud\nCall\'d on them who were dead.  Then fasting got\nThe mastery of grief.\"  Thus having spoke,\nOnce more upon the wretched skull his teeth\nHe fasten\'d, like a mastiff\'s \'gainst the bone\nFirm and unyielding.  Oh thou Pisa!  shame\nOf all the people, who their dwelling make\nIn that fair region, where th\' Italian voice\nIs heard, since that thy neighbours are so slack\nTo punish, from their deep foundations rise\nCapraia and Gorgona, and dam up\nThe mouth of Arno, that each soul in thee\nMay perish in the waters!  What if fame\nReported that thy castles were betray\'d\nBy Ugolino, yet no right hadst thou\nTo stretch his children on the rack.  For them,\nBrigata, Ugaccione, and the pair\nOf gentle ones, of whom my song hath told,\nTheir tender years, thou modern Thebes!  did make\nUncapable of guilt.  Onward we pass\'d,\nWhere others skarf\'d in rugged folds of ice\nNot on their feet were turn\'d, but each revers\'d\n     There very weeping suffers not to weep;\nFor at their eyes grief seeking passage finds\nImpediment, and rolling inward turns\nFor increase of sharp anguish:  the first tears\nHang cluster\'d, and like crystal vizors show,\nUnder the socket brimming all the cup.\n     Now though the cold had from my face dislodg\'d\nEach feeling, as \'t were callous, yet me seem\'d\nSome breath of wind I felt.  \"Whence cometh this,\"\nSaid I, \"my master?  Is not here below\nAll vapour quench\'d?\"--\"\'Thou shalt be speedily,\"\nHe answer\'d, \"where thine eye shall tell thee whence\nThe cause descrying of this airy shower.\"\n     Then cried out one in the chill crust who mourn\'d:\n\"O souls so cruel!  that the farthest post\nHath been assign\'d you, from this face remove\nThe harden\'d veil, that I may vent the grief\nImpregnate at my heart, some little space\nEre it congeal again!\"  I thus replied:\n\"Say who thou wast, if thou wouldst have mine aid;\nAnd if I extricate thee not, far down\nAs to the lowest ice may I descend!\"\n     \"The friar Alberigo,\" answered he,\n\"Am I, who from the evil garden pluck\'d\nIts fruitage, and am here repaid, the date\nMore luscious for my fig.\"--\"Hah!\"  I exclaim\'d,\n\"Art thou too dead!\"--\"How in the world aloft\nIt fareth with my body,\" answer\'d he,\n\"I am right ignorant.  Such privilege\nHath Ptolomea, that ofttimes the soul\nDrops hither, ere by Atropos divorc\'d.\nAnd that thou mayst wipe out more willingly\nThe glazed tear-drops that o\'erlay mine eyes,\nKnow that the soul, that moment she betrays,\nAs I did, yields her body to a fiend\nWho after moves and governs it at will,\nTill all its time be rounded; headlong she\nFalls to this cistern.  And perchance above\nDoth yet appear the body of a ghost,\nWho here behind me winters.  Him thou know\'st,\nIf thou but newly art arriv\'d below.\nThe years are many that have pass\'d away,\nSince to this fastness Branca Doria ca");
    strcat(expected_filecontent1, "me.\"\n     \"Now,\" answer\'d I, \"methinks thou mockest me,\nFor Branca Doria never yet hath died,\nBut doth all natural functions of a man,\nEats, drinks, and sleeps, and putteth raiment on.\"\n     He thus:  \"Not yet unto that upper foss\nBy th\' evil talons guarded, where the pitch\nTenacious boils, had Michael Zanche reach\'d,\nWhen this one left a demon in his stead\nIn his own body, and of one his kin,\nWho with him treachery wrought.  But now put forth\nThy hand, and ope mine eyes.\"  I op\'d them not.\nIll manners were best courtesy to him.\n     Ah Genoese!  men perverse in every way,\nWith every foulness stain\'d, why from the earth\nAre ye not cancel\'d?  Such an one of yours\nI with Romagna\'s darkest spirit found,\nAs for his doings even now in soul\nIs in Cocytus plung\'d, and yet doth seem\nIn body still alive upon the earth.\n\n\n\nCANTO XXXIV\n\n\"THE banners of Hell\'s Monarch do come forth\nTowards us; therefore look,\" so spake my guide,\n\"If thou discern him.\"  As, when");strcat(expected_filecontent2, "NOW was the day departing, and the air,\nImbrown\'d with shadows, from their toils releas\'d\nAll animals on earth; and I alone\nPrepar\'d myself the conflict to sustain,\nBoth of sad pity, and that perilous road,\nWhich my unerring memory shall retrace.\n     O Muses!  O high genius!  now vouchsafe\nYour aid!  O mind!  that all I saw hast kept\nSafe in a written record, here thy worth\nAnd eminent endowments come to proof.\n     I thus began:  \"Bard!  thou who art my guide,\nConsider well, if virtue be in me\nSufficient, ere to this high enterprise\nThou trust me.  Thou hast told that Silvius\' sire,\nYet cloth\'d in corruptible flesh, among\nTh\' immortal tribes had entrance, and was there\nSensible present.  Yet if heaven\'s great Lord,\nAlmighty foe to ill, such favour shew\'d,\nIn contemplation of the high effect,\nBoth what and who from him should issue forth,\nIt seems in reason\'s judgment well deserv\'d:\nSith he of Rome, and of Rome\'s empire wide,\nIn heaven\'s empyreal height was chosen sire:\nBoth which, if truth be spoken, were ordain\'d\nAnd \'stablish\'d for the holy place, where sits\nWho to great Peter\'s sacred chair succeeds.\nHe from this journey, in thy song renown\'d,\nLearn\'d things, that to his victory gave rise\nAnd to the papal robe.  In after-times\nThe chosen vessel also travel\'d there,\nTo bring us back assurance in that faith,\nWhich is the entrance to salvation\'s way.\nBut I, why should I there presume?  or who\nPermits it?  not, Aeneas I nor Paul.\nMyself I deem not worthy, and none else\nWill deem me.  I, if on this voyage then\nI venture, fear it will in folly end.\nThou, who art wise, better my meaning know\'st,\nThan I can speak.\"  As one, who unresolves\nWhat he hath late resolv\'d, and with new thoughts\nChanges his purpose, from his first intent\nRemov\'d; e\'en such was I on that dun coast,\nWasting in thought my enterprise, at first\nSo eagerly embrac\'d.  \"If right thy words\nI scan,\" replied that shade magnanimous,\n\"Thy soul is by vile fear assail\'d, which oft\nSo overcasts a man, that he recoils\nFrom noblest resolution, like a beast\nAt some false semblance in the twilight gloom.\nThat from this terror thou mayst free thyself,\nI will instruct thee why I came, and what\nI heard in that same instant, when for thee\nGrief touch\'d me first.  I was among the tribe,\nWho rest suspended, when a dame, so blest\nAnd lovely, I besought her to command,\nCall\'d me; her eyes were brighter than the star\nOf day; and she with gentle voice and soft\nAngelically tun\'d her speech address\'d:\n\"O courteous shade of Mantua!  thou whose fame\nYet lives, and shall live long as nature lasts!\nA friend, not of my fortune but myself,\nOn the wide desert in his road has met\nHindrance so great, that he through fear has turn\'d.\nNow much I dread lest he past help have stray\'d,\nAnd I be ris\'n too late for his relief,\nFrom what in heaven of him I heard.  Speed now,\nAnd by thy eloquent persuasive tongue,\nAnd by all means for his deliverance meet,\nAssist him.  So to me will comfort spring.\nI who now bid thee on this errand forth\nAm Beatrice; from a place I come\n\n(Note:  Beatrice.  I use this word, as it is\npronounced in the Italian, as consisting of four\nsyllables, of which the third is a long one.)\n\nRevisited with joy.  Love brought me thence,\nWho prompts my speech.  When in my Master\'s sight\nI stand, thy praise to him I oft will tell.\"\n     She then was silent, and I thus began:\n\"O Lady!  by whose influence alone,\nMankind excels whatever is contain\'d\nWithin that heaven which hath the smallest orb,\nSo thy command delights me, that to obey,\nIf it were done already, would seem late.\nNo need hast thou farther to speak thy will;\nYet tell the reason, why thou art not loth\nTo leave that ample space, where to return\nThou burnest, for this centre here beneath.\"\n     She then:  \"Since thou so deeply wouldst inquire,\nI will instruct thee briefly, why no dread\nHinders my entrance here.  Those things alone\nAre to be fear\'d, whence evil may proceed,\nNone else, for none are terrible beside.\nI am so fram\'d by God, thanks to his grace!\nThat any suff\'rance of your misery\nTouches me not, nor flame of tha");
    strcat(expected_filecontent2, "t fierce fire\nAssails me.  In high heaven a blessed dame\nBesides, who mourns with such effectual grief\nThat hindrance, which I send thee to remove,\nThat God\'s stern judgment to her will inclines.\nTo Lucia calling, her she thus bespake:\n\"Now doth thy faithful servant need thy aid\nAnd I commend him to thee.\"  At her word\nSped Lucia, of all cruelty the foe,\nAnd coming to the place, where I abode\nSeated with Rachel, her of ancient days,\nShe thus address\'d me: \"Thou true praise of God!\nBeatrice!  why is not thy succour lent\nTo him, who so much lov\'d thee, as to leave\nFor thy sake all the multitude admires?\nDost thou not hear how pitiful his wail,\nNor mark the death, which in the torrent flood,\nSwoln mightier than a sea, him struggling holds?\"\nNe\'er among men did any with such speed\nHaste to their profit, flee from their annoy,\nAs when these words were spoken, I came here,\nDown from my blessed seat, trusting the force\nOf thy pure eloquence, which thee, and all\nWho well have mark\'d it, into honour brings.\"\n     \"When she had ended, her bright beaming eyes\nTearful she turn\'d aside; whereat I felt\nRedoubled zeal to serve thee.  As she will\'d,\nThus am I come: I sav\'d thee from the beast,\nWho thy near way across the goodly mount\nPrevented.  What is this comes o\'er thee then?\nWhy, why dost thou hang back?  why in thy breast\nHarbour vile fear?  why hast not courage there\nAnd noble daring?  Since three maids so blest\nThy safety plan, e\'en in the court of heaven;\nAnd so much certain good my words forebode.\"\n     As florets, by the frosty air of night\nBent down and clos\'d, when day has blanch\'d their leaves,\nRise all unfolded on their spiry stems;\nSo was my fainting vigour new restor\'d,\nAnd to my heart such kindly courage ran,\nThat I as one undaunted soon replied:\n\"O full of pity she, who undertook\nMy succour!  and thou kind who didst perform\nSo soon her true behest!  With such desire\nThou hast dispos\'d me to renew my voyage,\nThat my first purpose fully is resum\'d.\nLead on: one only will is in us both.\nThou art my guide, my master thou, and lord.\"\n     So spake I; and when he had onward mov\'d,\nI enter\'d on the deep and woody way.\n\n\n\nCANTO III\n\n\"THROUGH me you pass into the city of woe:\nThrough me you pass into eternal pain:\nThrough me among the people lost for aye.\nJustice the founder of my fabric mov\'d:\nTo rear me was the task of power divine,\nSupremest wisdom, and primeval love.\nBefore me things create were none, save things\nEternal, and eternal I endure.\nAll hope abandon ye who enter here.\"\n     Such characters in colour dim I mark\'d\nOver a portal\'s lofty arch inscrib\'d:\nWhereat I thus: \"Master, these words import\nHard meaning.\"  He as one prepar\'d replied:\n\"Here thou must all distrust behind thee leave;\nHere be vile fear extinguish\'d. We are come\nWhere I have told thee we shall see the souls\nTo misery doom\'d, who intellectual good\nHave lost.\"  And when his hand he had stretch\'d forth\nTo mine, with pleasant looks, whence I was cheer\'d,\nInto that secret place he led me on.\n     Here sighs with lamentations and loud moans\nResounded through the air pierc\'d by no star,\nThat e\'en I wept at entering.  Various tongues,\nHorrible languages, outcries of woe,\nAccents of anger, voices deep and hoarse,\nWith hands together smote that swell\'d the sounds,\nMade up a tumult, that for ever whirls\nRound through that air with solid darkness stain\'d,\nLike to the sand that in the whirlwind flies.\n     I then, with error yet encompass\'d, cried:\n\"O master!  What is this I hear?  What race\nAre these, who seem so overcome with woe?\"\n     He thus to me: \"This miserable fate\nSuffer the wretched souls of those, who liv\'d\nWithout or praise or blame, with that ill band\nOf angels mix\'d, who nor rebellious prov\'d\nNor yet were true to God, but for themselves\nWere only.  From his bounds Heaven drove them forth,\nNot to impair his lustre, nor the depth\nOf Hell receives them, lest th\' accursed tribe\nShould glory thence with exultation vain.\"\n     I then: \"Master!  what doth aggrieve them thus,\nThat they lament so loud?\"  He straight replied:\n\"That will I tell thee briefl");
    strcat(expected_filecontent2, "y.  These of death\nNo hope may entertain: and their blind life\nSo meanly passes, that all other lots\nThey envy.  Fame of them the world hath none,\nNor suffers; mercy and justice scorn them both.\nSpeak not of them, but look, and pass them by.\"\n     And I, who straightway look\'d, beheld a flag,\nWhich whirling ran around so rapidly,\nThat it no pause obtain\'d: and following came\nSuch a long train of spirits, I should ne\'er\nHave thought, that death so many had despoil\'d.\n     When some of these I recogniz\'d, I saw\nAnd knew the shade of him, who to base fear\nYielding, abjur\'d his high estate.  Forthwith\nI understood for certain this the tribe\nOf those ill spirits both to God displeasing\nAnd to his foes.  These wretches, who ne\'er lived,\nWent on in nakedness, and sorely stung\nBy wasps and hornets, which bedew\'d their cheeks\nWith blood, that mix\'d with tears dropp\'d to their feet,\nAnd by disgustful worms was gather\'d there.\n     Then looking farther onwards I beheld\nA throng upon the shore of a great stream:\nWhereat I thus: \"Sir!  grant me now to know\nWhom here we view, and whence impell\'d they seem\nSo eager to pass o\'er, as I discern\nThrough the blear light?\"  He thus to me in few:\n\"This shalt thou know, soon as our steps arrive\nBeside the woeful tide of Acheron.\"\n     Then with eyes downward cast and fill\'d with shame,\nFearing my words offensive to his ear,\nTill we had reach\'d the river, I from speech\nAbstain\'d.  And lo!  toward us in a bark\nComes on an old man hoary white with eld,\nCrying, \"Woe to you wicked spirits!  hope not\nEver to see the sky again.  I come\nTo take you to the other shore across,\nInto eternal darkness, there to dwell\nIn fierce heat and in ice.  And thou, who there\nStandest, live spirit!  get thee hence, and leave\nThese who are dead.\"  But soon as he beheld\nI left them not, \"By other way,\" said he,\n\"By other haven shalt thou come to shore,\nNot by this passage; thee a nimbler boat\nMust carry.\"  Then to him thus spake my guide:\n\"Charon!  thyself torment not: so \'t is will\'d,\nWhere will and power are one: ask thou no more.\"\n     Straightway in silence fell the shaggy cheeks\nOf him the boatman o\'er the livid lake,\nAround whose eyes glar\'d wheeling flames.  Meanwhile\nThose spirits, faint and naked, color chang\'d,\nAnd gnash\'d their teeth, soon as the cruel words\nThey heard.  God and their parents they blasphem\'d,\nThe human kind, the place, the time, and seed\nThat did engender them and give them birth.\n     Then all together sorely wailing drew\nTo the curs\'d strand, that every man must pass\nWho fears not God.  Charon, demoniac form,\nWith eyes of burning coal, collects them all,\nBeck\'ning, and each, that lingers, with his oar\nStrikes.  As fall off the light autumnal leaves,\nOne still another following, till the bough\nStrews all its honours on the earth beneath;\nE\'en in like manner Adam\'s evil brood\nCast themselves one by one down from the shore,\nEach at a beck, as falcon at his call.\n     Thus go they over through the umber\'d wave,\nAnd ever they on the opposing bank\nBe landed, on this side another throng\nStill gathers.  \"Son,\" thus spake the courteous guide,\n\"Those, who die subject to the wrath of God,\nAll here together come from every clime,\nAnd to o\'erpass the river are not loth:\nFor so heaven\'s justice goads them on, that fear\nIs turn\'d into desire.  Hence ne\'er hath past\nGood spirit.  If of thee Charon complain,\nNow mayst thou know the import of his words.\"\n     This said, the gloomy region trembling shook\nSo terribly, that yet with clammy dews\nFear chills my brow.  The sad earth gave a blast,\nThat, lightening, shot forth a vermilion flame,\nWhich all my senses conquer\'d quite, and I\nDown dropp\'d, as one with sudden slumber seiz\'d.\n\n\n\nCANTO IV\n\nBROKE the deep slumber in my brain a crash\nOf heavy thunder, that I shook myself,\nAs one by main force rous\'d.  Risen upright,\nMy rested eyes I mov\'d around, and search\'d\nWith fixed ken to know what place it was,\nWherein I stood.  For certain on the brink\nI found me of the lamentable vale,\nThe dread abyss, that joins a thund\'rous sound\nOf plaints innumerable.  Dark and d");
    strcat(expected_filecontent2, "eep,\nAnd thick with clouds o\'erspread, mine eye in vain\nExplor\'d its bottom, nor could aught discern.\n     \"Now let us to the blind world there beneath\nDescend;\" the bard began all pale of look:\n\"I go the first, and thou shalt follow next.\"\n     Then I his alter\'d hue perceiving, thus:\n\"How may I speed, if thou yieldest to dread,\nWho still art wont to comfort me in doubt?\"\n     He then:  \"The anguish of that race below\nWith pity stains my che");strcat(expected_filecontent3, " that gate\nWe enter\'d first, whose threshold is to none\nDenied, nought else so worthy of regard,\nAs is this river, has thine eye discern\'d,\nO\'er which the flaming volley all is quench\'d.\"\n     So spake my guide; and I him thence besought,\nThat having giv\'n me appetite to know,\nThe food he too would give, that hunger crav\'d.\n     \"In midst of ocean,\" forthwith he began,\n\"A desolate country lies, which Crete is nam\'d,\nUnder whose monarch in old times the world\nLiv\'d pure and chaste.  A mountain rises there,\nCall\'d Ida, joyous once with leaves and streams,\nDeserted now like a forbidden thing.\nIt was the spot which Rhea, Saturn\'s spouse,\nChose for the secret cradle of her son;\nAnd better to conceal him, drown\'d in shouts\nHis infant cries.  Within the mount, upright\nAn ancient form there stands and huge, that turns\nHis shoulders towards Damiata, and at Rome\nAs in his mirror looks.  Of finest gold\nHis head is shap\'d, pure silver are the breast\nAnd arms; thence to the middle is of brass.\nAnd downward all beneath well-temper\'d steel,\nSave the right foot of potter\'s clay, on which\nThan on the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to the lowest depth of all,\nForm there Cocytus, of whose lake (thyself\nShall see it) I here give thee no account.\"\n     Then I to him:  \"If from our world this sluice\nBe thus deriv\'d; wherefore to us but now\nAppears it at this edge?\"  He straight replied:\n\"The place, thou know\'st, is round; and though great part\nThou have already pass\'d, still to the left\nDescending to the nethermost, not yet\nHast thou the circuit made of the whole orb.\nWherefore if aught of new to us appear,\nIt needs not bring up wonder in thy looks.\"\n     Then I again inquir\'d:  \"Where flow the streams\nOf Phlegethon and Lethe? for of one\nThou tell\'st not, and the other of that shower,\nThou say\'st, is form\'d.\"  He answer thus return\'d:\n\"Doubtless thy questions all well pleas\'d I hear.\nYet the red seething wave might have resolv\'d\nOne thou proposest.  Lethe thou shalt see,\nBut not within this hollow, in the place,\nWhither to lave themselves the spirits go,\nWhose blame hath been by penitence remov\'d.\"\nHe added:  \"Time is now we quit the wood.\nLook thou my steps pursue:  the margins give\nSafe passage, unimpeded by the flames;\nFor over them all vapour is extinct.\"\n\n\n\nCANTO XV\n\nOne of the solid margins bears us now\nEnvelop\'d in the mist, that from the stream\nArising, hovers o\'er, and saves from fire\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the mounds,\nSo fram\'d, though not in height or bulk to these\nMade equal, by the master, whosoe\'er\nHe was, that rais\'d them here.  We from the wood\nWere not so far remov\'d, that turning round\nI might not have discern\'d it, when we met\nA troop of spirits, who came beside the pier.\n     They each one ey\'d us, as at eventide\nOne eyes another under a new moon,\nAnd toward us sharpen\'d their sight as keen,\nAs an old tailor at his needle\'s eye.\n     Thus narrowly explor\'d by all the tribe,\nI was agniz\'d of one, who by the skirt\nCaught me, and cried, \"What wonder have we here!\"\n     And I, when he to me outstretch\'d his arm,\nIntently fix\'d my ken on his parch\'d looks,\nThat although smirch\'d with fire, they hinder\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent");
    strcat(expected_filecontent3, ";\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefore on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path descend to tread\nOn equal ground with him, but held my head\nBent down, as one who walks in reverent guise.\n     \"What chance or destiny,\" thus be began,\n\"Ere the last day conducts thee here below?\nAnd who is this, that shows to thee the way?\"\n     \"There up aloft,\" I answer\'d, \"in the life\nSerene, I wander\'d in a valley lost,\nBefore mine age had to its fullness reach\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d, and now strikes full upon my heart\nThe dear, benign, paternal image, such\nAs thine was, when so lately thou didst teach me\nThe way for man to win eternity;\nAnd how I priz\'d t");strcat(expected_filecontent4, "emons on our way we went;\nAh fearful company!  but in the church\nWith saints, with gluttons at the tavern\'s mess.\n     Still earnest on the pitch I gaz\'d, to mark\nAll things whate\'er the chasm contain\'d, and those\nWho burn\'d within.  As dolphins, that, in sign\nTo mariners, heave high their arched backs,\nThat thence forewarn\'d they may advise to save\nTheir threaten\'d vessels; so, at intervals,\nTo ease the pain his back some sinner show\'d,\nThen hid more nimbly than the lightning glance.\n     E\'en as the frogs, that of a wat\'ry moat\nStand at the brink, with the jaws only out,\nTheir feet and of the trunk all else concealed,\nThus on each part the sinners stood, but soon\nAs Barbariccia was at hand, so they\nDrew back under the wave.  I saw, and yet\nMy heart doth stagger, one, that waited thus,\nAs it befalls that oft one frog remains,\nWhile the next springs away:  and Graffiacan,\nWho of the fiends was nearest, grappling seiz\'d\nHis clotted locks, and dragg\'d him sprawling up,\nThat he appear\'d to me an otter.  Each\nAlready by their names I knew, so well\nWhen they were chosen, I observ\'d, and mark\'d\nHow one the other call\'d. \"O Rubicant!\nSee that his hide thou with thy talons flay,\"\nShouted together all the cursed crew.\n     Then I:  \"Inform thee, master!  if thou may,\nWhat wretched soul is this, on whom their hand\nHis foes have laid.\"  My leader to his side\nApproach\'d, and whence he came inquir\'d, to whom\nWas answer\'d thus:  \"Born in Navarre\'s domain\nMy mother plac\'d me in a lord\'s retinue,\nFor she had borne me to a losel vile,\nA spendthrift of his substance and himself.\nThe good king Thibault after that I serv\'d,\nTo peculating here my thoughts were turn\'d,\nWhereof I give account in this dire heat.\"\n     Straight Ciriatto, from whose mouth a tusk\nIssued on either side, as from a boar,\nRipt him with one of these.  \'Twixt evil claws\nThe mouse had fall\'n:  but Barbariccia cried,\nSeizing him with both arms:  \"Stand thou apart,\nWhile I do fix him on my prong transpierc\'d.\"\nThen added, turning to my guide his face,\n\"Inquire of him, if more thou wish to learn,\nEre he again be rent.\"  My leader thus:\n\"Then tell us of the partners in thy guilt;\nKnowest thou any sprung of Latian land\nUnder the tar?\"--\"I parted,\" he replied,\n\"But now from one, who sojourn\'d not far thence;\nSo were I under shelter now with him!\nNor hook nor talon then should scare me more.\"--.\n     \"Too long we suffer,\" Libicocco cried,\nThen, darting forth a prong, seiz\'d on his arm,\nAnd mangled bore away the sinewy part.\nHim Draghinazzo by his thighs beneath\nWould next have caught, whence angrily their chief,\nTurning on all sides round, with threat\'ning brow\nRestrain\'d them.  When their strife a little ceas\'d,\nOf him, who yet was gazing on his wound,\nMy teacher thus without delay inquir\'d:\n\"Who was the spirit, from whom by evil hap\nParting, as thou has told, thou cam\'st to shore?\"--\n     \"It was the friar Gomita,\" he rejoin\'d,\n\"He of Gallura, vessel of all guile,\nWho had his master\'s enemies in hand,\nAnd us\'d them so that they commend him well.\nMoney he took, and them at large dismiss\'d.\nSo he reports:  and in each other charge\nCommitted to his keeping, play\'d the part\nOf barterer to the height:   with him doth herd\nThe chief of Logodoro, Michel Zanche.\nSardinia is a theme, whereof their tongue\nIs never weary.  Out! alas! behold\nThat other, how he grins!  More would I say,\nBut tremble lest he mean to maul me sore.\"\n     Their captain then to Farfarello turning,\nWho roll\'d his moony eyes in act to strike,\nRebuk\'d him thus:  \"Off! cursed bird! Avaunt!\"--\n     \"If ye desire to see or hear,\" he thus\nQuaking with dread resum\'d, \"or Tuscan spirits\nOr Lombard, I will cause them to appear.\nMeantime let these ill talons bate their fury,\nSo that no vengeance they may fear from them,\nAnd I, remaining in this self-same place,\nWill for myself but one, make sev\'n appear,\nWhen my shrill whistle shall be heard; for so\nOur custom is to call each other up.\"\n     Cagnazzo at that word deriding grinn\'d,\nThen wagg\'d the head and spake:  \"Hear his device,\nMischievous as he is, to plunge him down");
    strcat(expected_filecontent4, ".\"\n     Whereto he thus, who fail\'d not in rich store\nOf nice-wove toils; \" Mischief forsooth extreme,\nMeant only to procure myself more woe!\"\n     No longer Alichino then refrain\'d,\nBut thus, the rest gainsaying, him bespake:\n\"If thou do cast thee down, I not on foot\nWill chase thee, but above the pitch will beat\nMy plumes.  Quit we the vantage ground, and let\nThe bank be as a shield, that we may see\nIf singly thou prevail against us all.\"\n     Now, reader, of new sport expect to hear!\n     They each one turn\'d his eyes to the\' other shore,\nHe first, who was the hardest to persuade.\nThe spirit of Navarre chose well his time,\nPlanted his feet on land, and at one leap\nEscaping disappointed their resolve.\n     Them quick resentment stung, but him the most,\nWho was the cause of failure; in pursuit\nHe therefore sped, exclaiming;  \"Thou art caught.\"\n     But little it avail\'d:  terror outstripp\'d\nHis following flight:  the other plung\'d beneath,\nAnd he with upward pinion rais\'d his breast:\nE\'en thus the water-fowl, when she perceives\nThe falcon near, dives instant down, while he\nEnrag\'d and spent retires.  That mockery\nIn Calcabrina fury stirr\'d, who flew\nAfter him, with desire of strife inflam\'d;\nAnd, for the barterer had \'scap\'d, so turn\'d\nHis talons on his comrade. O\'er the dyke\nIn grapple close they join\'d; but the\' other prov\'d\nA goshawk able to rend well his foe;\nAnd in the boiling lake both fell.  The heat\nWas umpire soon between them, but in vain\nTo lift themselves they strove, so fast were glued\nTheir pennons.  Barbariccia, as the rest,\nThat chance lamenting, four in flight dispatch\'d\nFrom the\' other coast, with all their weapons arm\'d.\nThey, to their post on each side speedily\nDescending, stretch\'d their hooks toward the fiends,\nWho flounder\'d, inly burning from their scars:\nAnd we departing left them to that broil.\n\n\n\nCANTO XXIII\n\nIN silence and in solitude we went,\nOne first, the other following his steps,\nAs minor friars journeying on their road.\n     The present fray had turn\'d my thoughts to muse\nUpon old Aesop\'s fable, where he told\nWhat fate unto the mouse and frog befell.\nFor language hath not sounds more like in sense,\nThan are these chances, if the origin\nAnd end of each be heedfully compar\'d.\nAnd as one thought b");strcat(expected_filecontent5, "mpts them,\nThey wait not for the motions of the will\nIn natures most sincere.  I did but smile,\nAs one who winks; and thereupon the shade\nBroke off, and peer\'d into mine eyes, where best\nOur looks interpret. \"So to good event\nMayst thou conduct such great emprize,\" he cried,\n\"Say, why across thy visage beam\'d, but now,\nThe lightning of a smile!\"  On either part\nNow am I straiten\'d; one conjures me speak,\nTh\' other to silence binds me: whence a sigh\nI utter, and the sigh is heard.  \"Speak on; \"\nThe teacher cried;  \"and do not fear to speak,\nBut tell him what so earnestly he asks.\"\nWhereon I thus:  \"Perchance, O ancient spirit!\nThou marvel\'st at my smiling. There is room\nFor yet more wonder.  He who guides my ken\nOn high, he is that Mantuan, led by whom\nThou didst presume of men arid gods to sing.\nIf other cause thou deem\'dst for which I smil\'d,\nLeave it as not the true one; and believe\nThose words, thou spak\'st of him, indeed the cause.\"\n     Now down he bent t\' embrace my teacher\'s feet;\nBut he forbade him:  \"Brother!  do it not:\nThou art a shadow, and behold\'st a shade.\"\nHe rising answer\'d thus:  \"Now hast thou prov\'d\nThe force and ardour of the love I bear thee,\nWhen I forget we are but things of air,\nAnd as a substance treat an empty shade.\"\n\n\n\nCANTO XXII\n\nNow we had left the angel, who had turn\'d\nTo the sixth circle our ascending step,\nOne gash from off my forehead raz\'d: while they,\nWhose wishes tend to justice, shouted forth:\n\"Bles");strcat(expected_filecontent6, "e had tended still\nThe thread and cordwain; and too late repents.\n     \"See next the wretches, who the needle left,\nThe shuttle and the spindle, and became\nDiviners:  baneful witcheries they wrought\nWith images and herbs.  But onward now:\nFor now doth Cain with fork of thorns confine\nOn either hemisphere, touching the wave\nBeneath the towers of Seville.  Yesternight\nThe moon was round.  Thou mayst remember well:\nFor she good service did thee in the gloom\nOf the deep wood.\"  This said, both onward mov\'d.\n\n\n\nCANTO XXI\n\nTHUS we from bridge to bridge, with other talk,\nThe which my drama cares not to rehearse,\nPass\'d on; and to the summit reaching, stood\nTo view another gap, within the round\nOf Malebolge, other bootless pangs.\n     Marvelous darkness shadow\'d o\'er the place.\n     In the Venetians\' arsenal as boils\nThrough wintry months tenacious pitch, to smear\nTheir unsound vessels; for th\' inclement time");


            struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            
                    struct file_t* file0 = file_open(volume, "LIKE.TX");
                    test_error(file0 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file1 = file_open(volume, "PASS");
                    test_error(file1 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file2 = file_open(volume, "WEEK");
                    test_error(file2 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file3 = file_open(volume, "FIT.TX");
                    test_error(file3 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file4 = file_open(volume, "ORDER.BIN");
                    test_error(file4 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file5 = file_open(volume, "CASE");
                    test_error(file5 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file6 = file_open(volume, "FINALFIG.TXT");
                    test_error(file6 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
            
                size_t size0 = file_read(filecontent0, 1, 10240, file0);
                test_error(size0 == 10240, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 10240 bajtów, a wczytała %lu", size0);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos0 = mem_find_first_difference(filecontent0, expected_filecontent0, 10240);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos0 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos0, mem_get_byte(filecontent0, diff_pos0), mem_get_byte(expected_filecontent0, diff_pos0));
        
                onerror_compare_memory(expected_filecontent0, filecontent0, 10240);
            
                size_t size1 = file_read(filecontent1, 1, 13248, file1);
                test_error(size1 == 13248, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 13248 bajtów, a wczytała %lu", size1);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos1 = mem_find_first_difference(filecontent1, expected_filecontent1, 13248);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos1 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos1, mem_get_byte(filecontent1, diff_pos1), mem_get_byte(expected_filecontent1, diff_pos1));
        
                onerror_compare_memory(expected_filecontent1, filecontent1, 13248);
            
                size_t size2 = file_read(filecontent2, 1, 12731, file2);
                test_error(size2 == 12731, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 12731 bajtów, a wczytała %lu", size2);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos2 = mem_find_first_difference(filecontent2, expected_filecontent2, 12731);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos2 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos2, mem_get_byte(filecontent2, diff_pos2), mem_get_byte(expected_filecontent2, diff_pos2));
        
                onerror_compare_memory(expected_filecontent2, filecontent2, 12731);
            
                size_t size3 = file_read(filecontent3, 1, 6348, file3);
                test_error(size3 == 6348, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6348 bajtów, a wczytała %lu", size3);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos3 = mem_find_first_difference(filecontent3, expected_filecontent3, 6348);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos3 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos3, mem_get_byte(filecontent3, diff_pos3), mem_get_byte(expected_filecontent3, diff_pos3));
        
                onerror_compare_memory(expected_filecontent3, filecontent3, 6348);
            
                size_t size4 = file_read(filecontent4, 1, 6363, file4);
                test_error(size4 == 6363, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6363 bajtów, a wczytała %lu", size4);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos4 = mem_find_first_difference(filecontent4, expected_filecontent4, 6363);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos4 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos4, mem_get_byte(filecontent4, diff_pos4), mem_get_byte(expected_filecontent4, diff_pos4));
        
                onerror_compare_memory(expected_filecontent4, filecontent4, 6363);
            
                size_t size5 = file_read(filecontent5, 1, 1461, file5);
                test_error(size5 == 1461, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1461 bajtów, a wczytała %lu", size5);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos5 = mem_find_first_difference(filecontent5, expected_filecontent5, 1461);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos5 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos5, mem_get_byte(filecontent5, diff_pos5), mem_get_byte(expected_filecontent5, diff_pos5));
        
                onerror_compare_memory(expected_filecontent5, filecontent5, 1461);
            
                size_t size6 = file_read(filecontent6, 1, 914, file6);
                test_error(size6 == 914, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 914 bajtów, a wczytała %lu", size6);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos6 = mem_find_first_difference(filecontent6, expected_filecontent6, 914);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos6 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos6, mem_get_byte(filecontent6, diff_pos6), mem_get_byte(expected_filecontent6, diff_pos6));
        
                onerror_compare_memory(expected_filecontent6, filecontent6, 914);
            

            free(filecontent0);
    free(filecontent1);
    free(filecontent2);
    free(filecontent3);
    free(filecontent4);
    free(filecontent5);
    free(filecontent6);

            file_close(file0);
    file_close(file1);
    file_close(file2);
    file_close(file3);
    file_close(file4);
    file_close(file5);
    file_close(file6);


            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 29: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST29(void)
{
    // informacje o teście
    test_start(29, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(1461, 1);
            char expected_filecontent[1462] = "";

            strcat(expected_filecontent, "mpts them,\nThey wait not for the motions of the will\nIn natures most sincere.  I did but smile,\nAs one who winks; and thereupon the shade\nBroke off, and peer\'d into mine eyes, where best\nOur looks interpret. \"So to good event\nMayst thou conduct such great emprize,\" he cried,\n\"Say, why across thy visage beam\'d, but now,\nThe lightning of a smile!\"  On either part\nNow am I straiten\'d; one conjures me speak,\nTh\' other to silence binds me: whence a sigh\nI utter, and the sigh is heard.  \"Speak on; \"\nThe teacher cried;  \"and do not fear to speak,\nBut tell him what so earnestly he asks.\"\nWhereon I thus:  \"Perchance, O ancient spirit!\nThou marvel\'st at my smiling. There is room\nFor yet more wonder.  He who guides my ken\nOn high, he is that Mantuan, led by whom\nThou didst presume of men arid gods to sing.\nIf other cause thou deem\'dst for which I smil\'d,\nLeave it as not the true one; and believe\nThose words, thou spak\'st of him, indeed the cause.\"\n     Now down he bent t\' embrace my teacher\'s feet;\nBut he forbade him:  \"Brother!  do it not:\nThou art a shadow, and behold\'st a shade.\"\nHe rising answer\'d thus:  \"Now hast thou prov\'d\nThe force and ardour of the love I bear thee,\nWhen I forget we are but things of air,\nAnd as a substance treat an empty shade.\"\n\n\n\nCANTO XXII\n\nNow we had left the angel, who had turn\'d\nTo the sixth circle our ascending step,\nOne gash from off my forehead raz\'d: while they,\nWhose wishes tend to justice, shouted forth:\n\"Bles");

            struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "CASE");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 1314, SEEK_SET);
        
            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[1314] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[1314], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 30: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST30(void)
{
    // informacje o teście
    test_start(30, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(12731, 1);
            char expected_filecontent[12732] = "";

            strcat(expected_filecontent, "NOW was the day departing, and the air,\nImbrown\'d with shadows, from their toils releas\'d\nAll animals on earth; and I alone\nPrepar\'d myself the conflict to sustain,\nBoth of sad pity, and that perilous road,\nWhich my unerring memory shall retrace.\n     O Muses!  O high genius!  now vouchsafe\nYour aid!  O mind!  that all I saw hast kept\nSafe in a written record, here thy worth\nAnd eminent endowments come to proof.\n     I thus began:  \"Bard!  thou who art my guide,\nConsider well, if virtue be in me\nSufficient, ere to this high enterprise\nThou trust me.  Thou hast told that Silvius\' sire,\nYet cloth\'d in corruptible flesh, among\nTh\' immortal tribes had entrance, and was there\nSensible present.  Yet if heaven\'s great Lord,\nAlmighty foe to ill, such favour shew\'d,\nIn contemplation of the high effect,\nBoth what and who from him should issue forth,\nIt seems in reason\'s judgment well deserv\'d:\nSith he of Rome, and of Rome\'s empire wide,\nIn heaven\'s empyreal height was chosen sire:\nBoth which, if truth be spoken, were ordain\'d\nAnd \'stablish\'d for the holy place, where sits\nWho to great Peter\'s sacred chair succeeds.\nHe from this journey, in thy song renown\'d,\nLearn\'d things, that to his victory gave rise\nAnd to the papal robe.  In after-times\nThe chosen vessel also travel\'d there,\nTo bring us back assurance in that faith,\nWhich is the entrance to salvation\'s way.\nBut I, why should I there presume?  or who\nPermits it?  not, Aeneas I nor Paul.\nMyself I deem not worthy, and none else\nWill deem me.  I, if on this voyage then\nI venture, fear it will in folly end.\nThou, who art wise, better my meaning know\'st,\nThan I can speak.\"  As one, who unresolves\nWhat he hath late resolv\'d, and with new thoughts\nChanges his purpose, from his first intent\nRemov\'d; e\'en such was I on that dun coast,\nWasting in thought my enterprise, at first\nSo eagerly embrac\'d.  \"If right thy words\nI scan,\" replied that shade magnanimous,\n\"Thy soul is by vile fear assail\'d, which oft\nSo overcasts a man, that he recoils\nFrom noblest resolution, like a beast\nAt some false semblance in the twilight gloom.\nThat from this terror thou mayst free thyself,\nI will instruct thee why I came, and what\nI heard in that same instant, when for thee\nGrief touch\'d me first.  I was among the tribe,\nWho rest suspended, when a dame, so blest\nAnd lovely, I besought her to command,\nCall\'d me; her eyes were brighter than the star\nOf day; and she with gentle voice and soft\nAngelically tun\'d her speech address\'d:\n\"O courteous shade of Mantua!  thou whose fame\nYet lives, and shall live long as nature lasts!\nA friend, not of my fortune but myself,\nOn the wide desert in his road has met\nHindrance so great, that he through fear has turn\'d.\nNow much I dread lest he past help have stray\'d,\nAnd I be ris\'n too late for his relief,\nFrom what in heaven of him I heard.  Speed now,\nAnd by thy eloquent persuasive tongue,\nAnd by all means for his deliverance meet,\nAssist him.  So to me will comfort spring.\nI who now bid thee on this errand forth\nAm Beatrice; from a place I come\n\n(Note:  Beatrice.  I use this word, as it is\npronounced in the Italian, as consisting of four\nsyllables, of which the third is a long one.)\n\nRevisited with joy.  Love brought me thence,\nWho prompts my speech.  When in my Master\'s sight\nI stand, thy praise to him I oft will tell.\"\n     She then was silent, and I thus began:\n\"O Lady!  by whose influence alone,\nMankind excels whatever is contain\'d\nWithin that heaven which hath the smallest orb,\nSo thy command delights me, that to obey,\nIf it were done already, would seem late.\nNo need hast thou farther to speak thy will;\nYet tell the reason, why thou art not loth\nTo leave that ample space, where to return\nThou burnest, for this centre here beneath.\"\n     She then:  \"Since thou so deeply wouldst inquire,\nI will instruct thee briefly, why no dread\nHinders my entrance here.  Those things alone\nAre to be fear\'d, whence evil may proceed,\nNone else, for none are terrible beside.\nI am so fram\'d by God, thanks to his grace!\nThat any suff\'rance of your misery\nTouches me not, nor flame of tha");
    strcat(expected_filecontent, "t fierce fire\nAssails me.  In high heaven a blessed dame\nBesides, who mourns with such effectual grief\nThat hindrance, which I send thee to remove,\nThat God\'s stern judgment to her will inclines.\nTo Lucia calling, her she thus bespake:\n\"Now doth thy faithful servant need thy aid\nAnd I commend him to thee.\"  At her word\nSped Lucia, of all cruelty the foe,\nAnd coming to the place, where I abode\nSeated with Rachel, her of ancient days,\nShe thus address\'d me: \"Thou true praise of God!\nBeatrice!  why is not thy succour lent\nTo him, who so much lov\'d thee, as to leave\nFor thy sake all the multitude admires?\nDost thou not hear how pitiful his wail,\nNor mark the death, which in the torrent flood,\nSwoln mightier than a sea, him struggling holds?\"\nNe\'er among men did any with such speed\nHaste to their profit, flee from their annoy,\nAs when these words were spoken, I came here,\nDown from my blessed seat, trusting the force\nOf thy pure eloquence, which thee, and all\nWho well have mark\'d it, into honour brings.\"\n     \"When she had ended, her bright beaming eyes\nTearful she turn\'d aside; whereat I felt\nRedoubled zeal to serve thee.  As she will\'d,\nThus am I come: I sav\'d thee from the beast,\nWho thy near way across the goodly mount\nPrevented.  What is this comes o\'er thee then?\nWhy, why dost thou hang back?  why in thy breast\nHarbour vile fear?  why hast not courage there\nAnd noble daring?  Since three maids so blest\nThy safety plan, e\'en in the court of heaven;\nAnd so much certain good my words forebode.\"\n     As florets, by the frosty air of night\nBent down and clos\'d, when day has blanch\'d their leaves,\nRise all unfolded on their spiry stems;\nSo was my fainting vigour new restor\'d,\nAnd to my heart such kindly courage ran,\nThat I as one undaunted soon replied:\n\"O full of pity she, who undertook\nMy succour!  and thou kind who didst perform\nSo soon her true behest!  With such desire\nThou hast dispos\'d me to renew my voyage,\nThat my first purpose fully is resum\'d.\nLead on: one only will is in us both.\nThou art my guide, my master thou, and lord.\"\n     So spake I; and when he had onward mov\'d,\nI enter\'d on the deep and woody way.\n\n\n\nCANTO III\n\n\"THROUGH me you pass into the city of woe:\nThrough me you pass into eternal pain:\nThrough me among the people lost for aye.\nJustice the founder of my fabric mov\'d:\nTo rear me was the task of power divine,\nSupremest wisdom, and primeval love.\nBefore me things create were none, save things\nEternal, and eternal I endure.\nAll hope abandon ye who enter here.\"\n     Such characters in colour dim I mark\'d\nOver a portal\'s lofty arch inscrib\'d:\nWhereat I thus: \"Master, these words import\nHard meaning.\"  He as one prepar\'d replied:\n\"Here thou must all distrust behind thee leave;\nHere be vile fear extinguish\'d. We are come\nWhere I have told thee we shall see the souls\nTo misery doom\'d, who intellectual good\nHave lost.\"  And when his hand he had stretch\'d forth\nTo mine, with pleasant looks, whence I was cheer\'d,\nInto that secret place he led me on.\n     Here sighs with lamentations and loud moans\nResounded through the air pierc\'d by no star,\nThat e\'en I wept at entering.  Various tongues,\nHorrible languages, outcries of woe,\nAccents of anger, voices deep and hoarse,\nWith hands together smote that swell\'d the sounds,\nMade up a tumult, that for ever whirls\nRound through that air with solid darkness stain\'d,\nLike to the sand that in the whirlwind flies.\n     I then, with error yet encompass\'d, cried:\n\"O master!  What is this I hear?  What race\nAre these, who seem so overcome with woe?\"\n     He thus to me: \"This miserable fate\nSuffer the wretched souls of those, who liv\'d\nWithout or praise or blame, with that ill band\nOf angels mix\'d, who nor rebellious prov\'d\nNor yet were true to God, but for themselves\nWere only.  From his bounds Heaven drove them forth,\nNot to impair his lustre, nor the depth\nOf Hell receives them, lest th\' accursed tribe\nShould glory thence with exultation vain.\"\n     I then: \"Master!  what doth aggrieve them thus,\nThat they lament so loud?\"  He straight replied:\n\"That will I tell thee briefl");
    strcat(expected_filecontent, "y.  These of death\nNo hope may entertain: and their blind life\nSo meanly passes, that all other lots\nThey envy.  Fame of them the world hath none,\nNor suffers; mercy and justice scorn them both.\nSpeak not of them, but look, and pass them by.\"\n     And I, who straightway look\'d, beheld a flag,\nWhich whirling ran around so rapidly,\nThat it no pause obtain\'d: and following came\nSuch a long train of spirits, I should ne\'er\nHave thought, that death so many had despoil\'d.\n     When some of these I recogniz\'d, I saw\nAnd knew the shade of him, who to base fear\nYielding, abjur\'d his high estate.  Forthwith\nI understood for certain this the tribe\nOf those ill spirits both to God displeasing\nAnd to his foes.  These wretches, who ne\'er lived,\nWent on in nakedness, and sorely stung\nBy wasps and hornets, which bedew\'d their cheeks\nWith blood, that mix\'d with tears dropp\'d to their feet,\nAnd by disgustful worms was gather\'d there.\n     Then looking farther onwards I beheld\nA throng upon the shore of a great stream:\nWhereat I thus: \"Sir!  grant me now to know\nWhom here we view, and whence impell\'d they seem\nSo eager to pass o\'er, as I discern\nThrough the blear light?\"  He thus to me in few:\n\"This shalt thou know, soon as our steps arrive\nBeside the woeful tide of Acheron.\"\n     Then with eyes downward cast and fill\'d with shame,\nFearing my words offensive to his ear,\nTill we had reach\'d the river, I from speech\nAbstain\'d.  And lo!  toward us in a bark\nComes on an old man hoary white with eld,\nCrying, \"Woe to you wicked spirits!  hope not\nEver to see the sky again.  I come\nTo take you to the other shore across,\nInto eternal darkness, there to dwell\nIn fierce heat and in ice.  And thou, who there\nStandest, live spirit!  get thee hence, and leave\nThese who are dead.\"  But soon as he beheld\nI left them not, \"By other way,\" said he,\n\"By other haven shalt thou come to shore,\nNot by this passage; thee a nimbler boat\nMust carry.\"  Then to him thus spake my guide:\n\"Charon!  thyself torment not: so \'t is will\'d,\nWhere will and power are one: ask thou no more.\"\n     Straightway in silence fell the shaggy cheeks\nOf him the boatman o\'er the livid lake,\nAround whose eyes glar\'d wheeling flames.  Meanwhile\nThose spirits, faint and naked, color chang\'d,\nAnd gnash\'d their teeth, soon as the cruel words\nThey heard.  God and their parents they blasphem\'d,\nThe human kind, the place, the time, and seed\nThat did engender them and give them birth.\n     Then all together sorely wailing drew\nTo the curs\'d strand, that every man must pass\nWho fears not God.  Charon, demoniac form,\nWith eyes of burning coal, collects them all,\nBeck\'ning, and each, that lingers, with his oar\nStrikes.  As fall off the light autumnal leaves,\nOne still another following, till the bough\nStrews all its honours on the earth beneath;\nE\'en in like manner Adam\'s evil brood\nCast themselves one by one down from the shore,\nEach at a beck, as falcon at his call.\n     Thus go they over through the umber\'d wave,\nAnd ever they on the opposing bank\nBe landed, on this side another throng\nStill gathers.  \"Son,\" thus spake the courteous guide,\n\"Those, who die subject to the wrath of God,\nAll here together come from every clime,\nAnd to o\'erpass the river are not loth:\nFor so heaven\'s justice goads them on, that fear\nIs turn\'d into desire.  Hence ne\'er hath past\nGood spirit.  If of thee Charon complain,\nNow mayst thou know the import of his words.\"\n     This said, the gloomy region trembling shook\nSo terribly, that yet with clammy dews\nFear chills my brow.  The sad earth gave a blast,\nThat, lightening, shot forth a vermilion flame,\nWhich all my senses conquer\'d quite, and I\nDown dropp\'d, as one with sudden slumber seiz\'d.\n\n\n\nCANTO IV\n\nBROKE the deep slumber in my brain a crash\nOf heavy thunder, that I shook myself,\nAs one by main force rous\'d.  Risen upright,\nMy rested eyes I mov\'d around, and search\'d\nWith fixed ken to know what place it was,\nWherein I stood.  For certain on the brink\nI found me of the lamentable vale,\nThe dread abyss, that joins a thund\'rous sound\nOf plaints innumerable.  Dark and d");
    strcat(expected_filecontent, "eep,\nAnd thick with clouds o\'erspread, mine eye in vain\nExplor\'d its bottom, nor could aught discern.\n     \"Now let us to the blind world there beneath\nDescend;\" the bard began all pale of look:\n\"I go the first, and thou shalt follow next.\"\n     Then I his alter\'d hue perceiving, thus:\n\"How may I speed, if thou yieldest to dread,\nWho still art wont to comfort me in doubt?\"\n     He then:  \"The anguish of that race below\nWith pity stains my che");

            struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "WEEK");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, -362, SEEK_END);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[12369] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[12369], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 31: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST31(void)
{
    // informacje o teście
    test_start(31, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(6348, 1);
            char expected_filecontent[6349] = "";

            strcat(expected_filecontent, " that gate\nWe enter\'d first, whose threshold is to none\nDenied, nought else so worthy of regard,\nAs is this river, has thine eye discern\'d,\nO\'er which the flaming volley all is quench\'d.\"\n     So spake my guide; and I him thence besought,\nThat having giv\'n me appetite to know,\nThe food he too would give, that hunger crav\'d.\n     \"In midst of ocean,\" forthwith he began,\n\"A desolate country lies, which Crete is nam\'d,\nUnder whose monarch in old times the world\nLiv\'d pure and chaste.  A mountain rises there,\nCall\'d Ida, joyous once with leaves and streams,\nDeserted now like a forbidden thing.\nIt was the spot which Rhea, Saturn\'s spouse,\nChose for the secret cradle of her son;\nAnd better to conceal him, drown\'d in shouts\nHis infant cries.  Within the mount, upright\nAn ancient form there stands and huge, that turns\nHis shoulders towards Damiata, and at Rome\nAs in his mirror looks.  Of finest gold\nHis head is shap\'d, pure silver are the breast\nAnd arms; thence to the middle is of brass.\nAnd downward all beneath well-temper\'d steel,\nSave the right foot of potter\'s clay, on which\nThan on the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to the lowest depth of all,\nForm there Cocytus, of whose lake (thyself\nShall see it) I here give thee no account.\"\n     Then I to him:  \"If from our world this sluice\nBe thus deriv\'d; wherefore to us but now\nAppears it at this edge?\"  He straight replied:\n\"The place, thou know\'st, is round; and though great part\nThou have already pass\'d, still to the left\nDescending to the nethermost, not yet\nHast thou the circuit made of the whole orb.\nWherefore if aught of new to us appear,\nIt needs not bring up wonder in thy looks.\"\n     Then I again inquir\'d:  \"Where flow the streams\nOf Phlegethon and Lethe? for of one\nThou tell\'st not, and the other of that shower,\nThou say\'st, is form\'d.\"  He answer thus return\'d:\n\"Doubtless thy questions all well pleas\'d I hear.\nYet the red seething wave might have resolv\'d\nOne thou proposest.  Lethe thou shalt see,\nBut not within this hollow, in the place,\nWhither to lave themselves the spirits go,\nWhose blame hath been by penitence remov\'d.\"\nHe added:  \"Time is now we quit the wood.\nLook thou my steps pursue:  the margins give\nSafe passage, unimpeded by the flames;\nFor over them all vapour is extinct.\"\n\n\n\nCANTO XV\n\nOne of the solid margins bears us now\nEnvelop\'d in the mist, that from the stream\nArising, hovers o\'er, and saves from fire\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the mounds,\nSo fram\'d, though not in height or bulk to these\nMade equal, by the master, whosoe\'er\nHe was, that rais\'d them here.  We from the wood\nWere not so far remov\'d, that turning round\nI might not have discern\'d it, when we met\nA troop of spirits, who came beside the pier.\n     They each one ey\'d us, as at eventide\nOne eyes another under a new moon,\nAnd toward us sharpen\'d their sight as keen,\nAs an old tailor at his needle\'s eye.\n     Thus narrowly explor\'d by all the tribe,\nI was agniz\'d of one, who by the skirt\nCaught me, and cried, \"What wonder have we here!\"\n     And I, when he to me outstretch\'d his arm,\nIntently fix\'d my ken on his parch\'d looks,\nThat although smirch\'d with fire, they hinder\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent");
    strcat(expected_filecontent, ";\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefore on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path descend to tread\nOn equal ground with him, but held my head\nBent down, as one who walks in reverent guise.\n     \"What chance or destiny,\" thus be began,\n\"Ere the last day conducts thee here below?\nAnd who is this, that shows to thee the way?\"\n     \"There up aloft,\" I answer\'d, \"in the life\nSerene, I wander\'d in a valley lost,\nBefore mine age had to its fullness reach\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d, and now strikes full upon my heart\nThe dear, benign, paternal image, such\nAs thine was, when so lately thou didst teach me\nThe way for man to win eternity;\nAnd how I priz\'d t");

            struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "FIT.TX");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 533, SEEK_SET);
            file_seek(file, 4149, SEEK_CUR);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[4682] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[4682], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 32: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST32(void)
{
    // informacje o teście
    test_start(32, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "BUT");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (BUT) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 33: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST33(void)
{
    // informacje o teście
    test_start(33, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "CENTURY");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (CENTURY) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 34: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST34(void)
{
    // informacje o teście
    test_start(34, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "NORTH");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (NORTH) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 35: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST35(void)
{
    // informacje o teście
    test_start(35, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "KNOW");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (KNOW) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 36: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST36(void)
{
    // informacje o teście
    test_start(36, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "WHICH");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (WHICH) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 37: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST37(void)
{
    // informacje o teście
    test_start(37, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "MEETMANY");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (MEETMANY) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 38: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST38(void)
{
    // informacje o teście
    test_start(38, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "CENTER.TX");
            test_error(file == NULL, "Funkcja file_open() nie powinna otworzyć pliku o nazwie CENTER.TX, ponieważ nie istnieje on w katalogu głównym");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 39: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST39(void)
{
    // informacje o teście
    test_start(39, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, "CENTER.TX");
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 40: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST40(void)
{
    // informacje o teście
    test_start(40, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 41: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST41(void)
{
    // informacje o teście
    test_start(41, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 42: Sprawdzanie poprawności działania funkcji file_close
//
void UTEST42(void)
{
    // informacje o teście
    test_start(42, "Sprawdzanie poprawności działania funkcji file_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            file_close(NULL);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 43: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST43(void)
{
    // informacje o teście
    test_start(43, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "LIKE.TX");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int res = file_read(NULL, 1, 1, file);
            test_error(res == -1, "Funkcja file_read() powinna zwrócić wartość -1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 44: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST44(void)
{
    // informacje o teście
    test_start(44, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[13] = { "LIKE.TX", "PASS", "WEEK", "FIT.TX", "ORDER.BIN", "CASE", "FINALFIG.TXT", "BUT", "CENTURY", "NORTH", "KNOW", "WHICH", "MEETMANY" };
            int found_names[13] = { 0 };

            struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 13; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 13; ++j)
                {
                    if (strcmp(entry.name, expected_names[j]) == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 45: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST45(void)
{
    // informacje o teście
    test_start(45, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "LIKE.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 46: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST46(void)
{
    // informacje o teście
    test_start(46, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "PASS");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 47: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST47(void)
{
    // informacje o teście
    test_start(47, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "WEEK");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 48: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST48(void)
{
    // informacje o teście
    test_start(48, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "FIT.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 49: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST49(void)
{
    // informacje o teście
    test_start(49, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "ORDER.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 50: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST50(void)
{
    // informacje o teście
    test_start(50, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "CASE");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 51: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST51(void)
{
    // informacje o teście
    test_start(51, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "FINALFIG.TXT");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 52: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST52(void)
{
    // informacje o teście
    test_start(52, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("proper_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t*  dir = dir_open(volume, "apple");
            test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}




enum run_mode_t { rm_normal_with_rld = 0, rm_unit_test = 1, rm_main_test = 2 };

int __wrap_main(volatile int _argc, char** _argv, char** _envp)
{
    int volatile vargc = _argc;
    char ** volatile vargv = _argv, ** volatile venvp = _envp;
	volatile enum run_mode_t run_mode = rm_unit_test; // -1
	volatile int selected_test = -1;

    if (vargc > 1)
	{
	    char* smode = strtok(vargv[1], ",");
	    char* stest = strtok(NULL, "");
		char *errptr = NULL;
		run_mode = (enum run_mode_t)strtol(smode, &errptr, 10);
		if (*errptr == '\x0')
		{
			memmove(vargv + 1, vargv + 2, sizeof(char*) * (vargc - 1));
			vargc--;

			if (stest != NULL)
			{
			    int val = (int)strtol(stest, &errptr, 10);
			    if (*errptr == '\x0')
			        selected_test = val;
			}
		}
	}

    // printf("runmode=%d; selected_test=%d\n", run_mode, selected_test);

    // inicjuj testy jednostkowe
    unit_test_init(run_mode, "unit_test_v2.c");
    test_limit_init();
    rldebug_set_reported_severity_level(MSL_FAILURE);

    if (run_mode == rm_normal_with_rld)
    {
        // konfiguracja ograniczników
        rldebug_reset_limits();
        

        // uruchom funkcję main Studenta a potem wyświetl podsumowanie sterty i zasobów
        volatile int ret_code = rdebug_call_main(tested_main, vargc, vargv, venvp);

        rldebug_reset_limits();
        

        int leaks_detected = rldebug_show_leaked_resources(0);
        if (leaks_detected)
            raise(SIGHEAP);

        return ret_code;
    }

    
    if (run_mode == rm_unit_test)
    {
        test_title("Testy jednostkowe");

        void (*pfcn[])(void) =
        { 
            UTEST1, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST2, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST3, // Sprawdzanie poprawności działania funkcji disk_close
            UTEST4, // Sprawdzanie poprawności działania funkcji fat_open
            UTEST5, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST6, // Sprawdzanie poprawności działania funkcji file_read
            UTEST7, // Sprawdzanie poprawności działania funkcji file_read
            UTEST8, // Sprawdzanie poprawności działania funkcji file_read
            UTEST9, // Sprawdzanie poprawności działania funkcji file_read
            UTEST10, // Sprawdzanie poprawności działania funkcji file_read
            UTEST11, // Sprawdzanie poprawności działania funkcji file_read
            UTEST12, // Sprawdzanie poprawności działania funkcji file_read
            UTEST13, // Sprawdzanie poprawności działania funkcji file_read
            UTEST14, // Sprawdzanie poprawności działania funkcji file_read
            UTEST15, // Sprawdzanie poprawności działania funkcji file_read
            UTEST16, // Sprawdzanie poprawności działania funkcji file_read
            UTEST17, // Sprawdzanie poprawności działania funkcji file_read
            UTEST18, // Sprawdzanie poprawności działania funkcji file_read
            UTEST19, // Sprawdzanie poprawności działania funkcji file_read
            UTEST20, // Sprawdzanie poprawności działania funkcji file_read
            UTEST21, // Sprawdzanie poprawności działania funkcji file_read
            UTEST22, // Sprawdzanie poprawności działania funkcji file_read
            UTEST23, // Sprawdzanie poprawności działania funkcji file_read
            UTEST24, // Sprawdzanie poprawności działania funkcji file_read
            UTEST25, // Sprawdzanie poprawności działania funkcji file_read
            UTEST26, // Sprawdzanie poprawności działania funkcji file_read
            UTEST27, // Sprawdzanie poprawności działania funkcji file_read
            UTEST28, // Sprawdzanie poprawności działania funkcji file_read
            UTEST29, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST30, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST31, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST32, // Sprawdzanie poprawności działania funkcji file_open
            UTEST33, // Sprawdzanie poprawności działania funkcji file_open
            UTEST34, // Sprawdzanie poprawności działania funkcji file_open
            UTEST35, // Sprawdzanie poprawności działania funkcji file_open
            UTEST36, // Sprawdzanie poprawności działania funkcji file_open
            UTEST37, // Sprawdzanie poprawności działania funkcji file_open
            UTEST38, // Sprawdzanie poprawności działania funkcji file_open
            UTEST39, // Sprawdzanie poprawności działania funkcji file_read
            UTEST40, // Sprawdzanie poprawności działania funkcji file_read
            UTEST41, // Sprawdzanie poprawności działania funkcji file_read
            UTEST42, // Sprawdzanie poprawności działania funkcji file_close
            UTEST43, // Sprawdzanie poprawności działania funkcji file_read
            UTEST44, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST45, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST46, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST47, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST48, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST49, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST50, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST51, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST52, // Sprawdzanie poprawności działania funkcji dir_open
            NULL
        };

        for (int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx]();

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(52); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem
        return EXIT_SUCCESS;
    }
    

    if (run_mode == rm_main_test)
    {
        test_title("Testy funkcji main()");

        void (*pfcn[])(int, char**, char**) =
        { 
            NULL
        };

        for (volatile int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx](vargc, vargv, venvp);

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(0); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem

        return EXIT_SUCCESS;
    }

    printf("*** Nieznana wartość RunMode: %d", (int)run_mode);
    abort();
}