<GameFile>
  <PropertyGroup Name="GameOverLayer" Type="Layer" ID="2ddf0c64-0acd-48b3-a384-db6a7e6d5610" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Layer" CustomClassName="GameOverLayer" Tag="875" ctype="GameLayerObjectData">
        <Size X="480.0000" Y="320.0000" />
        <Children>
          <AbstractNodeData Name="Panel_1" ActionTag="-2080996590" Tag="876" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" TouchEnable="True" ClipAble="False" BackColorAlpha="102" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
            <Size X="480.0000" Y="320.0000" />
            <Children>
              <AbstractNodeData Name="FinishText" ActionTag="-1286296938" Tag="877" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="111.0000" RightMargin="111.0000" TopMargin="104.0000" BottomMargin="168.0000" FontSize="48" LabelText="YOU WON!" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="258.0000" Y="48.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="240.0000" Y="192.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="28" G="242" B="28" />
                <PrePosition X="0.5000" Y="0.6000" />
                <PreSize X="0.5375" Y="0.1500" />
                <FontResource Type="Normal" Path="fonts/INVASION2000.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Panel_2" ActionTag="1773134324" Tag="878" IconVisible="False" PositionPercentXEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="52.4880" RightMargin="52.4880" TopMargin="163.0000" BottomMargin="57.0000" ClipAble="False" BackColorAlpha="102" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                <Size X="375.0240" Y="100.0000" />
                <Children>
                  <AbstractNodeData Name="ExitButton" ActionTag="823453761" ZOrder="2" CallBackType="Click" CallBackName="onExitToMenu" Tag="879" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="30.0207" RightMargin="30.0207" TopMargin="50.6700" BottomMargin="17.3300" TouchEnable="True" FontSize="36" ButtonText="Exit" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="56" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="314.9827" Y="32.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="187.5120" Y="33.3300" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.3333" />
                    <PreSize X="0.8399" Y="0.3200" />
                    <FontResource Type="Normal" Path="fonts/INVASION2000.TTF" Plist="" />
                    <TextColor A="255" R="255" G="0" B="0" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="RestartButton" ActionTag="-1836128004" ZOrder="1" CallBackType="Click" CallBackName="onRestart" Tag="880" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="30.0207" RightMargin="30.0207" TopMargin="8.6700" BottomMargin="59.3300" TouchEnable="True" FontSize="36" ButtonText="Restart" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="128" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="314.9827" Y="32.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="187.5120" Y="75.3300" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.7533" />
                    <PreSize X="0.8399" Y="0.3200" />
                    <FontResource Type="Normal" Path="fonts/INVASION2000.TTF" Plist="" />
                    <TextColor A="255" R="255" G="255" B="0" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" />
                <Position X="240.0000" Y="57.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.1781" />
                <PreSize X="0.7813" Y="0.3125" />
                <SingleColor A="255" R="150" G="200" B="255" />
                <FirstColor A="255" R="150" G="200" B="255" />
                <EndColor A="255" R="255" G="255" B="255" />
                <ColorVector ScaleY="1.0000" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="240.0000" Y="160.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>