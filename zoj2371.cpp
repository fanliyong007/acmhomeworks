#include<bits/stdc++.h>
#define ll unsigned long long int
char str[101][101] =
    {
        {"1"},
        {"3"},
        {"9"},
        {"27"},
        {"81"},
        {"243"},
        {"729"},
        {"2187"},
        {"6561"},
        {"19683"},
        {"59049"},
        {"177147"},
        {"531441"},
        {"1594323"},
        {"4782969"},
        {"14348907"},
        {"43046721"},
        {"129140163"},
        {"387420489"},
        {"1162261467"},
        {"3486784401"},
        {"10460353203"},
        {"31381059609"},
        {"94143178827"},
        {"282429536481"},
        {"847288609443"},
        {"2541865828329"},
        {"7625597484987"},
        {"22876792454961"},
        {"68630377364883"},
        {"205891132094649"},
        {"617673396283947"},
        {"1853020188851841"},
        {"5559060566555523"},
        {"16677181699666569"},
        {"50031545098999707"},
        {"150094635296999121"},
        {"450283905890997363"},
        {"1350851717672992089"},
        {"4052555153018976267"},
        {"12157665459056928801"},
        {"36472996377170786403"},
        {"109418989131512359209"},
        {"328256967394537077627"},
        {"984770902183611232881"},
        {"2954312706550833698643"},
        {"8862938119652501095929"},
        {"26588814358957503287787"},
        {"79766443076872509863361"},
        {"239299329230617529590083"},
        {"717897987691852588770249"},
        {"2153693963075557766310747"},
        {"6461081889226673298932241"},
        {"19383245667680019896796723"},
        {"58149737003040059690390169"},
        {"174449211009120179071170507"},
        {"523347633027360537213511521"},
        {"1570042899082081611640534563"},
        {"4710128697246244834921603689"},
        {"14130386091738734504764811067"},
        {"42391158275216203514294433201"},
        {"127173474825648610542883299603"},
        {"381520424476945831628649898809"},
        {"1144561273430837494885949696427"},
        {"3433683820292512484657849089281"},
        {"10301051460877537453973547267843"},
        {"30903154382632612361920641803529"},
        {"92709463147897837085761925410587"},
        {"278128389443693511257285776231761"},
        {"834385168331080533771857328695283"},
        {"2503155504993241601315571986085849"},
        {"7509466514979724803946715958257547"},
        {"22528399544939174411840147874772641"},
        {"67585198634817523235520443624317923"},
        {"202755595904452569706561330872953769"},
        {"608266787713357709119683992618861307"},
        {"1824800363140073127359051977856583921"},
        {"5474401089420219382077155933569751763"},
        {"16423203268260658146231467800709255289"},
        {"49269609804781974438694403402127765867"},
        {"147808829414345923316083210206383297601"},
        {"443426488243037769948249630619149892803"},
        {"1330279464729113309844748891857449678409"},
        {"3990838394187339929534246675572349035227"},
        {"11972515182562019788602740026717047105681"},
        {"35917545547686059365808220080151141317043"},
        {"107752636643058178097424660240453423951129"},
        {"323257909929174534292273980721360271853387"},
        {"969773729787523602876821942164080815560161"},
        {"2909321189362570808630465826492242446680483"},
        {"8727963568087712425891397479476727340041449"},
        {"26183890704263137277674192438430182020124347"},
        {"78551672112789411833022577315290546060373041"},
        {"235655016338368235499067731945871638181119123"},
        {"706965049015104706497203195837614914543357369"},
        {"2120895147045314119491609587512844743630072107"},
        {"6362685441135942358474828762538534230890216321"},
        {"19088056323407827075424486287615602692670648963"},
        {"57264168970223481226273458862846808078011946889"},
        {"171792506910670443678820376588540424234035840667"},
        {"515377520732011331036461129765621272702107522001"}};
int main()
{
    ll n;
    int num[101];
    while (true)
    {
        scanf("%lld", &n);
        if(n==0)
            break;
        int g=0;
        int flag = 0;
        ll x = n - 1;
        while(x>0)
        {
            num[g] = x % 2;
            if(num[g]==1)
                flag = g;
            x /= 2;
            g++;
        }
        if(n==1)
        {
            printf("{ }\n");
            continue;
        }
        printf("{");
        for (int i = 0; i < g;i++)
            if(num[i]==1)
                if(i!=flag)
                    printf(" %s,", str[i]);
                else
                    printf(" %s", str[i]);
        printf(" }\n");
    }
}